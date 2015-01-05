#include "player.h"
#include "rumidiaplayer.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RumidiaPlayer w;
    w.show();
    
    if (HIWORD(BASS_GetVersion())!=BASSVERSION) {
        QMessageBox::information(0, "失败", "An incorrect version of BASS.DLL was loaded.");
        //return 0; 这里的返回值的意思是？
    }

    return a.exec();
}
