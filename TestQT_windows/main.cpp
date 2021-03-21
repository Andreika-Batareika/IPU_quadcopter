#include "mainwindow.h"
#include <QApplication>
#include "ui_mainwindow.h"
#include "msg.h"

#include "serialportreader.h"


#include <ctime> // подключаем clock

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();




}
