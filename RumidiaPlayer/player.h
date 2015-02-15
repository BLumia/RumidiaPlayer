#ifndef PLAYER_H
#define PLAYER_H
#include <QString>
#include <QFileInfo>
#include "bass.h"
#include "bassmidi.h"

namespace Ui {
class Player;
}

class Player
{
public:
    Player();
    ~Player();

    bool Play();
    bool Pause();
    bool Stop();
    bool isSFLoaded();
    QString LoadMidiFile(QString file);
    void setNOFX(bool isEnabled);
    QString loadSF(QString file);
    QString getTitle();
    int getPlayProgress();
    int getProgressRular();// 根据当前所载入的曲目设置进度条的大小
    bool devInit();
    QString getCurTime();
    QString getSFName();
    QString getSFLoaded();
    double getMidiBPM();
    bool getPlayState();
    void ApplyTempo(bool reset = false);
    void SetTempo(int pos);
    void setVol(int vol);
    void SetPos(int pos);
    void DBGSetTempo(int pos);

    //HSTREAM chan;		// channel handle
    HSOUNDFONT font;	// soundfont
    //int miditempo;		// MIDI file tempo
    int actualMidiTempo;    // 实际的Tempo
    //float temposcale=1;	// tempo adjustment

private:
    Ui::Player *ui;
    bool NOFXChecked;   // A CheckBox's state
    bool isPlaying;
};

#endif // PLAYER_H
