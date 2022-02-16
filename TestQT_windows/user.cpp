#include "user.h"
#include <QDebug>
#include <QMutex>
#include <avto.h>
#include <mainwindow.h>

#include <chrono>
#include <thread>

QRecursiveMutex mtx1;
user::user(MainWindow *mwThiscome, QObject *parent)
    : QObject(parent), mwThis(mwThiscome) {}
/*
user::user(mathmodel *com_math_model, avtopilot *come_system_avtomatic,
           std::vector<Tpoint> come_waypoints) {
  math_model = com_math_model;
  system_avtomatic = come_system_avtomatic;
  operation_mode = "avto";
  waypoints = come_waypoints;
}
*/
// получение новой КТ (записсь в массив котрольных точек )
void user::Get_way_point(std::vector<float> vector) {}

// передача контрольной точки
void user::Set_way_point(std::vector<float> vector) {}

// функция двигателей зависящааая от поставленной задачи (он же  и вызвает
// автопилот)
float *user::target() {}

//пользовательская процедура
float *user::User_mode(std::vector<float> vector) {}
// основная процедурая, выполняемая в каждом проходе основной программы
void user::Change_mode(std::vector<float> vector, float inTime) {
  if (operation_mode == "avto")
    system_avtomatic->F_avto(vector);
}

void user::MainProgramm() {
  int i = 0;
  while (true) {
    i++;
    // mwThis->readText("d", mwThis->ui);
    //   mwThis->uitextEdit->setText(QString::number(i));
    qDebug() << i;

    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    mtx1.lock();
    this->setMessage(QString::number(vectorReadFromUSB[0]));
    std::vector<float> outArray =
        this->system_avtomatic->F_avto(vectorReadFromUSB);
    mtx1.unlock();
  }
  //  this->WUser->Change_mode(comevector,);
}
user::~user() {}

void user::setRunning(bool running) {
  if (m_running == running)
    return;
  m_running = running;
  Q_EMIT runningChanged(running);
}

void user::setMessage(QString message) {

  // m_message = message;
  Q_EMIT messageChanged(message);
}
