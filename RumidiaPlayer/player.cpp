#include "player.h"
#include <QMessageBox>

float temposcale=1;	// tempo adjustment
HSTREAM chan;		// channel handle
int miditempo;		// MIDI file tempo

void CALLBACK TempoSync(HSYNC handle, DWORD channel, DWORD data, void *user)
{
    miditempo = BASS_MIDI_StreamGetEvent(chan,0,MIDI_EVENT_TEMPO);
    BASS_MIDI_StreamEvent(chan,0,MIDI_EVENT_TEMPO,miditempo*temposcale); // set tempo
}

Player::Player()
{
    //加载解码插件
    BASS_PluginLoad("bassmidi.dll", 0);
    isPlaying = false;
}

Player::~Player()
{
    BASS_Free();
    BASS_PluginFree(0);
}

bool Player::devInit()
{
    return BASS_Init(-1, 48000, 0, 0, NULL);
}

QString Player::LoadMidiFile(QString file)
{
    BASS_StreamFree(chan); // free old stream before opening new
    chan=BASS_MIDI_StreamCreateFile(false,file.toStdWString().c_str(),0,0,BASS_SAMPLE_LOOP|(NOFXChecked?0:BASS_MIDI_NOFX),1);
    if (!chan)//创建流是否成功
    {
        // it ain't a MIDI
        int a = BASS_ErrorGetCode();
        QString s = QString::number(a, 10);  //10表示十进制
        QMessageBox::information(0, "Error", "打开文件错误，错误代码：\nBASS_"+s);
        return "Error_Open_File";
        // override the initial tempo, and set a sync to override tempo events and another to override after seeking
        ApplyTempo(true);
        BASS_ChannelSetSync(chan,BASS_SYNC_MIDI_EVENT|BASS_SYNC_MIXTIME,MIDI_EVENT_TEMPO,TempoSync,0);
        BASS_ChannelSetSync(chan,BASS_SYNC_SETPOS|BASS_SYNC_MIXTIME,0,TempoSync,0);
    }
    //BASS_ChannelPlay(chan,FALSE);
    return "It_Is_Done";
}

int Player::getPlayProgress(){
    //MESS(21,TBM_SETPOS,1,(DWORD)BASS_ChannelGetPosition(chan,BASS_POS_MIDI_TICK)/120); // update position
    if (chan) {
        return (DWORD)BASS_ChannelGetPosition(chan,BASS_POS_MIDI_TICK)/120;
    } else {
        return -1;
    }
}

int Player::getProgressRular(){
    if (chan) {
        return BASS_ChannelGetLength(chan,BASS_POS_MIDI_TICK)/120;
    } else {
        return -1;
    }
}

bool Player::Play()
{
    if (chan) {
        isPlaying = true;
        BASS_ChannelPlay(chan,FALSE);
        return true;
    } else {
        return false;
    }
}

bool Player::Pause()
{
    if (chan) {
        isPlaying = false;
        BASS_ChannelPause(chan);
        return true;
    } else {
        return false;
    }
}

bool Player::Stop()
{
    if (chan) {
        isPlaying = false;
        BASS_ChannelStop(chan);
        return true;
    } else {
        return false;
    }
}

void Player::ApplyTempo(bool reset)
{
    if (reset) { // 如果重置则取得tempo并重置
        miditempo = BASS_MIDI_StreamGetEvent(chan,0,MIDI_EVENT_TEMPO);
    }
    BASS_MIDI_StreamEvent(chan,0,MIDI_EVENT_TEMPO,miditempo*temposcale); // set tempo
}

bool Player::getPlayState(){
    return isPlaying;
}

QString Player::getTitle()
{
    if (!chan)//是否有载入
    {
        return "No_File_Loaded";
    }
    BASS_MIDI_MARK mark;
    if (BASS_MIDI_StreamGetMark(chan,BASS_MIDI_MARK_TRACK,0,&mark) && !mark.track)
        return QString(mark.text);
    else
        return "NULL_Title_In_Midi";
}

QString Player::getCurTime()
{
    int totalSec = (int)BASS_ChannelBytes2Seconds(chan,BASS_ChannelGetPosition(chan, BASS_POS_BYTE));
    int minute = totalSec/60;
    int second = totalSec%60;
    if (second != -1)
    {
        if(second < 10)
            return QString::number(minute) + ":0" + QString::number(second);
        else
            return QString::number(minute) + ":" + QString::number(second);
    } else {
        return "00:00";
    }
}

QString Player::loadSF(QString file)
{
    HSOUNDFONT newfont=BASS_MIDI_FontInit(file.toStdWString().c_str(),0);
    if (newfont)
    {
        BASS_MIDI_FONT sf;
        sf.font=newfont;
        sf.preset=-1; // use all presets
        sf.bank=0; // use default bank(s)
        BASS_MIDI_StreamSetFonts(0,&sf,1); // set default soundfont
        BASS_MIDI_StreamSetFonts(chan,&sf,1); // set for current stream too
        BASS_MIDI_FontFree(font); // free old soundfont
        font=newfont;
    } else {
        return "Error_Load_SoundFont";
    }
    return "It_Is_Done";
}

QString Player::getSFName(){
    if (font) {
        BASS_MIDI_FONTINFO i;
        BASS_MIDI_FontGetInfo(font,&i);
        return QString(i.name);
    }
    return "Unable_Get_SF_Name";
}

QString Player::getSFLoaded(){
    if (font) {
        BASS_MIDI_FONTINFO i;
        BASS_MIDI_FontGetInfo(font,&i);
        QString s = QString::number(i.samload, 10);
        QString ss = QString::number(i.samsize, 10);
        return s + "/" + ss;
    }
    return "Unable_Get_SF_SampLoadInfo";
}

void Player::SetTempo(int pos){
    temposcale=1/((30-pos)/20.f); // up to +/- 50% bpm
    ApplyTempo(); // apply the tempo adjustment
}

void Player::setNOFX(bool isEnabled){
    NOFXChecked = isEnabled;
    if (NOFXChecked)
        BASS_ChannelFlags(chan,0,BASS_MIDI_NOFX); // enable FX
    else
        BASS_ChannelFlags(chan,BASS_MIDI_NOFX,BASS_MIDI_NOFX); // disable FX
}

void Player::SetPos(int pos){
    BASS_ChannelSetPosition(chan,pos*120,BASS_POS_MIDI_TICK);
}

void Player::setVol(int vol)
{
    //设置音量，0最小，100最大
    float v = (float)vol/100;
    BASS_ChannelSetAttribute(chan, BASS_ATTRIB_VOL, v);
}

bool Player::isSFLoaded(){
    if (font) return true;
    else return false;
}
