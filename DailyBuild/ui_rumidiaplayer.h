/********************************************************************************
** Form generated from reading UI file 'rumidiaplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUMIDIAPLAYER_H
#define UI_RUMIDIAPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "spslider.h"

QT_BEGIN_NAMESPACE

class Ui_RumidiaPlayer
{
public:
    QWidget *centralWidget;
    QLabel *titleLabel;
    QPushButton *loadFileBtn;
    QGroupBox *soundFontBox;
    QLabel *curSFLabel;
    QPushButton *loadSFBtn;
    QLabel *SFNameLabel;
    QLabel *SFInsLoadedLabel;
    SPSlider *progressSlider;
    QPushButton *playBtn;
    QGroupBox *controlBox;
    QSlider *tempoSlider;
    QLabel *tempoLabel;
    QCheckBox *NOFXCheckBox;
    QLCDNumber *lcdNumber;
    SPSlider *volSlider;

    void setupUi(QMainWindow *RumidiaPlayer)
    {
        if (RumidiaPlayer->objectName().isEmpty())
            RumidiaPlayer->setObjectName(QStringLiteral("RumidiaPlayer"));
        RumidiaPlayer->resize(353, 320);
        centralWidget = new QWidget(RumidiaPlayer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        titleLabel = new QLabel(centralWidget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setGeometry(QRect(120, 30, 211, 20));
        loadFileBtn = new QPushButton(centralWidget);
        loadFileBtn->setObjectName(QStringLiteral("loadFileBtn"));
        loadFileBtn->setGeometry(QRect(20, 110, 41, 41));
        soundFontBox = new QGroupBox(centralWidget);
        soundFontBox->setObjectName(QStringLiteral("soundFontBox"));
        soundFontBox->setGeometry(QRect(20, 190, 311, 111));
        curSFLabel = new QLabel(soundFontBox);
        curSFLabel->setObjectName(QStringLiteral("curSFLabel"));
        curSFLabel->setGeometry(QRect(20, 20, 180, 16));
        loadSFBtn = new QPushButton(soundFontBox);
        loadSFBtn->setObjectName(QStringLiteral("loadSFBtn"));
        loadSFBtn->setGeometry(QRect(240, 20, 51, 20));
        SFNameLabel = new QLabel(soundFontBox);
        SFNameLabel->setObjectName(QStringLiteral("SFNameLabel"));
        SFNameLabel->setGeometry(QRect(20, 45, 271, 16));
        SFInsLoadedLabel = new QLabel(soundFontBox);
        SFInsLoadedLabel->setObjectName(QStringLiteral("SFInsLoadedLabel"));
        SFInsLoadedLabel->setGeometry(QRect(20, 70, 271, 16));
        progressSlider = new SPSlider(centralWidget);
        progressSlider->setObjectName(QStringLiteral("progressSlider"));
        progressSlider->setGeometry(QRect(20, 80, 311, 20));
        progressSlider->setMaximum(99);
        progressSlider->setSliderPosition(0);
        progressSlider->setOrientation(Qt::Horizontal);
        playBtn = new QPushButton(centralWidget);
        playBtn->setObjectName(QStringLiteral("playBtn"));
        playBtn->setGeometry(QRect(70, 110, 41, 41));
        controlBox = new QGroupBox(centralWidget);
        controlBox->setObjectName(QStringLiteral("controlBox"));
        controlBox->setGeometry(QRect(380, 30, 171, 161));
        tempoSlider = new QSlider(controlBox);
        tempoSlider->setObjectName(QStringLiteral("tempoSlider"));
        tempoSlider->setGeometry(QRect(130, 40, 22, 101));
        tempoSlider->setMaximum(20);
        tempoSlider->setValue(10);
        tempoSlider->setOrientation(Qt::Vertical);
        tempoLabel = new QLabel(controlBox);
        tempoLabel->setObjectName(QStringLiteral("tempoLabel"));
        tempoLabel->setGeometry(QRect(120, 20, 31, 16));
        NOFXCheckBox = new QCheckBox(controlBox);
        NOFXCheckBox->setObjectName(QStringLiteral("NOFXCheckBox"));
        NOFXCheckBox->setGeometry(QRect(20, 20, 91, 16));
        NOFXCheckBox->setChecked(true);
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(20, 30, 91, 40));
        lcdNumber->setFrameShape(QFrame::Box);
        lcdNumber->setFrameShadow(QFrame::Raised);
        volSlider = new SPSlider(centralWidget);
        volSlider->setObjectName(QStringLiteral("volSlider"));
        volSlider->setGeometry(QRect(250, 110, 81, 20));
        volSlider->setMaximum(100);
        volSlider->setValue(100);
        volSlider->setOrientation(Qt::Horizontal);
        RumidiaPlayer->setCentralWidget(centralWidget);

        retranslateUi(RumidiaPlayer);

        QMetaObject::connectSlotsByName(RumidiaPlayer);
    } // setupUi

    void retranslateUi(QMainWindow *RumidiaPlayer)
    {
        RumidiaPlayer->setWindowTitle(QApplication::translate("RumidiaPlayer", "RumidiaPlayer", 0));
        titleLabel->setText(QApplication::translate("RumidiaPlayer", "No File Loaded", 0));
        loadFileBtn->setText(QApplication::translate("RumidiaPlayer", "Load", 0));
        soundFontBox->setTitle(QApplication::translate("RumidiaPlayer", "Sound Font", 0));
        curSFLabel->setText(QApplication::translate("RumidiaPlayer", "No SoundFont Loaded", 0));
        loadSFBtn->setText(QApplication::translate("RumidiaPlayer", "Load...", 0));
        SFNameLabel->setText(QApplication::translate("RumidiaPlayer", "SoundFont Name:", 0));
        SFInsLoadedLabel->setText(QApplication::translate("RumidiaPlayer", "SoundFont Loaded:", 0));
        playBtn->setText(QApplication::translate("RumidiaPlayer", "Play", 0));
        controlBox->setTitle(QApplication::translate("RumidiaPlayer", "Control Panel", 0));
        tempoLabel->setText(QApplication::translate("RumidiaPlayer", "Tempo", 0));
        NOFXCheckBox->setText(QApplication::translate("RumidiaPlayer", "Reverb&Chorus", 0));
    } // retranslateUi

};

namespace Ui {
    class RumidiaPlayer: public Ui_RumidiaPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUMIDIAPLAYER_H
