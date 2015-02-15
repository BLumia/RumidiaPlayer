#ifndef RUMIDIAPLAYER_H
#define RUMIDIAPLAYER_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtCore>
#include <QtGui>
#include "player.h"
#include "spslider.h"

namespace Ui {
class RumidiaPlayer;
}

class RumidiaPlayer : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit RumidiaPlayer(QWidget *parent = 0);
    ~RumidiaPlayer();
    
private slots:
    void UpdateTime();
    void on_loadFileBtn_clicked();
    void on_NOFXCheckBox_clicked();
    void on_loadSFBtn_clicked();

    void on_playBtn_clicked();
    void applyTempo();

    void on_progressSlider_sliderPressed();

    void on_progressSlider_sliderReleased();

    void on_progressSlider_valueChanged(int value);

    void on_volSlider_valueChanged(int value);

    void on_dbgBtn_clicked();

private:
    Ui::RumidiaPlayer *ui;
    Player *player;
    QTimer *timer;
    bool isPlaySliderPressed;
};

#endif // RUMIDIAPLAYER_H
