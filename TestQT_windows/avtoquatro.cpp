#include "avtoquatro.h"

avtoquatro::avtoquatro()
{

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
   float avtoquatro::F_throttle_p(float read_pitch,float mission_pitch)//
   {

   }



float  avtoquatro::F_throttle_r(float read_roll,float mission_roll)
{

}


float  avtoquatro::F_throttle_H()
{

}

void avtoquatro::mission_stabilizacia(float p,float tp,float r,float tr)// (один из режимов автопилота)
{

}



float* avtoquatro::F_avto(float vector1[])// функция автомитизации , обрабатывается если включен режим автопилота
{

}
