#include "avtoquatro.h"
#include <avto.h>

avtoquatro::avtoquatro(float inmass):avtopilot (inmass)
{
    P_pitch=0;
    D_pitch=0;
    P_roll=0;
    D_roll=0;
    mass=0;
    G=9.8*mass;


        mission_roll=0;
        error_pitch=0;
        error_roll=0;
        error_roll_previous=0;
        error_pitch_previous=0;
        mission_pitch=0;
        throttle_mission_avto_z=1500;
        throttle_mission_r=0;

    //    self.vector_status=[[0],0,0,0,0,0,0,0,0,0,0,0,0];//d X Y Z vx vy vz health pitch roll wx wy wz
        dt=0.1;
     //   throttle={0,0,0,0}// левый передний, правый передний,левый задний, правый задний

}

float avtoquatro::f_Forse(float P,float D,float error, float spin) //функция PID
{

}

float avtoquatro::f_Pitch(float pitch,float target_pitch) // функция получения разницы сил от номинала для необходимого угла тангажа
{

}
   float  avtoquatro::f_Roll(float roll,float target_roll)// функция получения разницы сил от номинала для необходимого угла крена
   {

   }



   //можно опустить



 /*
    float avtoquatro::F_throttle_p(float read_pitch,float mission_pitch)//
   {

   }



float  avtoquatro::F_throttle_r(float read_roll,float mission_roll)
{

}

*/
// можно опустить

float  avtoquatro::F_throttle_H() // функция для вычисления мощности  двигатеоей для поддержания заданной высоты
{

}

void avtoquatro::mission_stabilizacia(float p,float tp,float r,float tr)// (один из режимов автопилота)
{

}



float* avtoquatro::F_avto(float vector1[])// функция автомитизации , обрабатывается если включен режим автопилота
{

}
