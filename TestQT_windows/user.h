#ifndef USER_H
#define USER_H
#include <avto.h>
#include <avtoquatro.h>
#include <mathmodel.h>
#include <mathmodel_quatro.h>
#include <tpoint.h>
#include <vector>
class user {
public:
  user(mathmodel *com_math_model, avtopilot *come_system_avtomatic,
       std::vector<Tpoint> come_waypoints);

  mathmodel *math_model;       // математическая модель
  avtopilot *system_avtomatic; // тип автопилота
  std::string operation_mode; // режим управления в данный момент
  void add_waypoints(Tpoint come_waypoint); //добавить котнрольную точку
  void Get_way_point(std::vector<float> vector);
  // ??

  void Set_way_point(std::vector<float> vector);
  // ??
  float *target(); // функция
  std::vector<Tpoint> waypoints;
  float *User_mode(std::vector<float> vector);
  // пользовательский режим пилотриования
  void Change_mode(std::vector<float> vector, float inTime);
  // процедура обработки данных и управление в
  // зависимости от режима управления
};

#endif // USER_H
