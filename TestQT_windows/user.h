#ifndef USER_H
#define USER_H
#include <QObject>
#include <avto.h>
#include <avtoquatro.h>
#include <mathmodel.h>
#include <mathmodel_quatro.h>
#include <tpoint.h>
#include <vector>
class MainWindow;

static std::vector<float> vectorReadFromUSB(20);

class user : public QObject {
  Q_OBJECT

public:
  bool m_running;
  QString m_message = "Ok";
  QString m_message_2;
  int count; // Счётчик, по которому будем ориентироваться на то,
             // что потоки выполняются и работают

  bool running;
  QString message;
  // user(mathmodel *com_math_model, avtopilot *come_system_avtomatic,
  //     std::vector<Tpoint> come_waypoints);
  explicit user(MainWindow *mwThiscome, QObject *parent = nullptr);
  ~user();
  mathmodel *math_model;       // математическая модель
  avtopilot *system_avtomatic; // тип автопилота
  std::string operation_mode; // режим управления в данный момент
  void add_waypoints(Tpoint come_waypoint); //добавить котнрольную точку
  void Get_way_point(std::vector<float> vector);
  void Set_way_point(std::vector<float> vector);
  float *target(); // функция
  std::vector<Tpoint> waypoints;
  float *User_mode(std::vector<float> vector);
  // пользовательский режим пилотриования
  void Change_mode(std::vector<float> vector, float inTime);
  // процедура обработки данных и управление в
  // зависимости от режима управления
public:
  MainWindow *mwThis = nullptr;

Q_SIGNALS:
  void finished(); // Сигнал, по которому будем завершать поток, после
                   // завершения метода run
  void runningChanged(bool running);
  void messageChanged(QString message);
  void sendMessage(QString message);

public Q_SLOTS:
  void MainProgramm();
  void run(){}; // Метод с полезной нагрузкой, который может выполняться в цикле
  void setRunning(bool running);
  void setMessage(QString message);
  void setMessage_2(QString message_2){};
};

#endif // USER_H
