#include "rumidiaplayer.h"
#include "ui_rumidiaplayer.h"

RumidiaPlayer::RumidiaPlayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RumidiaPlayer)
{
    ui->setupUi(this);
    player = new Player();//播放功能封装
    timer = new QTimer(this);//定时器

    player->devInit();

    //信号与槽
    connect(timer,SIGNAL(timeout()),this,SLOT(UpdateTime()));
    connect(ui->tempoSlider, SIGNAL(valueChanged(int)), this, SLOT(applyTempo()));

    isPlaySliderPressed = false;
    timer->start(27);//定时器太慢会触发进度条setValue的BUG
}

void RumidiaPlayer::applyTempo()
{
    player->SetTempo(ui->tempoSlider->sliderPosition());
}

RumidiaPlayer::~RumidiaPlayer()
{
    delete ui;
    delete player;
    delete timer;
}

void RumidiaPlayer::UpdateTime()
{
    //进度条部分
    int pos = player->getPlayProgress();
    if ((pos != -1)&&(isPlaySliderPressed == false))//当进度条按下时，不自动滚动
        ui->progressSlider->setSliderPosition(pos);

    //播放的时间显示
    ui->lcdNumber->display(player->getCurTime());
    //音源加载信息
    static int updatefont=0;
    if (player->isSFLoaded() && ++updatefont&1)//不要太频繁的更新啦..
        ui->SFInsLoadedLabel->setText("SoundFont Loaded:"+player->getSFLoaded());
    //可能会实时改变的BPM
    ui->tempoLabel->setText(QString::number(player->getMidiBPM(), 'f', 1));

    return;
}

void RumidiaPlayer::on_loadFileBtn_clicked()
{
    QString files = QFileDialog::getOpenFileName(this, QString::fromUtf8("打开"),0,QString::fromUtf8("MIDI文件 (*.mid *.midi *rmi *kar);;常见的MIDI文件 (*.mid *.midi);;不常见的MIDI文件 (*.rmi *.kar)"));
    if (!files.isEmpty())
    {
        // clear lyrics display here if i add lrc function
        ui->titleLabel->setText(QFileInfo(files).fileName());
        QString loadState = player->LoadMidiFile(files);
        if (loadState == "Error_Open_File") {
            ui->titleLabel->setText("创建流失败");
            return;
        }
        //从midi文件获取标题
        loadState = player->getTitle();
        if (loadState != "NULL_Title_In_Midi") {
            ui->titleLabel->setText(loadState);
        }
        //设置进度条宽度(using tick length)
        int pgslen = player->getProgressRular();
        if (pgslen != -1)
            ui->progressSlider->setMaximum(pgslen);
        //设置音量
        player->setVol(ui->volSlider->value());
        //显示Tempo（353
        ui->tempoLabel->setText(QString::number(player->getMidiBPM(), 'f', 1));
    }
}

void RumidiaPlayer::on_NOFXCheckBox_clicked()
{
    player->setNOFX(ui->NOFXCheckBox->isChecked());
}

void RumidiaPlayer::on_loadSFBtn_clicked()
{
    QString files = QFileDialog::getOpenFileName(this, QString::fromUtf8("打开"),0,QString::fromUtf8("音源文件 (*.sf2 *.sf2pack)"));
    if (!files.isEmpty())
    {
        // clear lyrics display here if i add lrc function
        QString loadState = player->loadSF(files);
        if (loadState == "Error_Load_SoundFont") ui->curSFLabel->setText("加载音源失败");
        ui->curSFLabel->setText(QFileInfo(files).fileName());
        ui->SFNameLabel->setText("SoundFont Name:"+player->getSFName());
        ui->SFInsLoadedLabel->setText("SoundFont Loaded:"+player->getSFLoaded());
        // _snprintf(text,sizeof(text),"name: %s\nloaded: %d / %d",i.name,i.samload,i.samsize);
    }
}

void RumidiaPlayer::on_playBtn_clicked()
{
    if (player->getPlayState()){
        if (player->Pause())
            ui->playBtn->setText("Play");
    } else {
        if (player->Play())
            ui->playBtn->setText("Pause");
    }
}


void RumidiaPlayer::on_progressSlider_sliderPressed()
{
    isPlaySliderPressed = true;
}

void RumidiaPlayer::on_progressSlider_sliderReleased()
{
    isPlaySliderPressed = false;
    player->SetPos(ui->progressSlider->sliderPosition());
}

void RumidiaPlayer::on_progressSlider_valueChanged(int value)
{
    //防止进度发生变更时，递归触发setPos
    if (qAbs(player->getPlayProgress() - value) > 2)
    {
        player->SetPos(value);
    }
}

void RumidiaPlayer::on_volSlider_valueChanged(int value)
{
    player->setVol(value);
}

void RumidiaPlayer::on_dbgBtn_clicked()
{
    player->DBGSetTempo(5);
}
