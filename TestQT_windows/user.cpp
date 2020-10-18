#include "user.h"

user::user (mathmodel com_math_model, avto come_system_avtomatic, std::vector<Tpoint> come_waypoints)
{
   self.math_model=com_math_model;
     self.system_avtomatic=come_system_avtomatic;
      self.operation_mode="avto";
      self.waypoints= come_waypoints;
}

// получение новой КТ (записсь в массив котрольных точек )
void user::Get_way_point(float vector[])
{
}

// передача контрольной точки
 void  user::Set_way_point(float vector[])
 {

 }

 // функция двигателей зависящааая от поставленной задачи (он же  и вызвает автопилот)
 float* user::target(self)
 {

 }

 //пользовательская процедура
 float* user::User_mode(float vector[])
 {

 }
 // основная процедурая, выполняемая в каждом проходе основной программы
 void user::Change_mode(float vector[])
 {

 }
