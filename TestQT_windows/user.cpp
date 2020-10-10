#include "user.h"

user::user (mathmodel com_math_model, avto come_system_avtomatic, Tpoint* come_waypoints)
{
   self.math_model=com_math_model;
     self.system_avtomatic=come_system_avtomatic;
      self.operation_mode="avto";
      self.waypoints= come_waypoints;
}

void user::Get_way_point(float vector[])
{
}

 void  user::Set_way_point(float vector[])
 {

 }
 float* user::ttarget(self)
 {

 }

 float* user::User_mode(float vector[])
 {

 }
 void user::Change_mode(float vector[])
 {

 }
