#include "mainwindow.h"
#include "msg.h"
#include "ui_mainwindow.h"
#include <QApplication>

#include "serialportreader.h"

#include <mutex>
#include <thread>

#include <ctime> // подключаем clock

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  MainWindow w;

  w.show();

  return a.exec();
}
