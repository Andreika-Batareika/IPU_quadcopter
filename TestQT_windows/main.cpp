#include "mainwindow.h"
#include <QApplication>
#include "ui_mainwindow.h"
#include "msg.h"

#include <ctime> // подключаем clock

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    MSG  Msg ;
    return a.exec();
    int time1 ;
    while (true)
    {

        std::string readingString= Msg.readport(0);
        w.setStringToVector(readingString);
        int time0 =clock();
        float dt10= (time0-time1)*1000000;
        time1=time0;

        w.WUser->math_model->analiz_vector(w.WUser->system_avtomatic->vector_status, (float)time1);
        w.WUser->Change_mode(w.WUser->system_avtomatic->vector_status,dt10);
        w.setVectorToString();
        int time2 =clock();
        float dt12 = (time2-time1)*1000000;
        int timef =clock();
        Msg.writeport(0);

    }

}
