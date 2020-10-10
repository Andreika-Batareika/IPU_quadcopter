#ifndef USER_H
#define USER_H
#include <mathmodel.h>
#include <avto.h>
#include <tpoint.h>
class user
{
public:
    user( mathmodel com_math_model, avto come_system_avtomatic, Tpoint* come_waypoints);


       mathmodel    math_model;// математическая модель
        avto   system_avtomatic;// тип автопилота
         string  operation_mode; // режим управления в данный момент


void add_waypoints(Tpoint come_waypoint); //добавить котнрольную точку
       void Get_way_point(float vector[]); // ??

        void  Set_way_point(float vector[]);// ??
        float* ttarget(self);// функция
Tpoint* waypoints;
        float* User_mode(float vector[]);// пользовательский режим пилотриования
        void Change_mode(float vector[]);// процедура обработки данных и управление в зависимости от режима управления

};

#endif // USER_H
