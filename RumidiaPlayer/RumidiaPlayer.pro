#-------------------------------------------------
#
# Project created by QtCreator 2014-08-23T16:15:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RumidiaPlayer
TEMPLATE = app


SOURCES += main.cpp\
        rumidiaplayer.cpp \
    player.cpp \
    spslider.cpp

HEADERS  += rumidiaplayer.h \
    player.h \
    spslider.h

FORMS    += rumidiaplayer.ui

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/

LIBS += -L$$PWD/ -lbass
PRE_TARGETDEPS += $$PWD/bass.lib
LIBS += -L$$PWD/ -lbassmidi
PRE_TARGETDEPS += $$PWD/bassmidi.lib