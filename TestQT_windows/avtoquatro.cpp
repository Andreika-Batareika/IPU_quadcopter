#include "avtoquatro.h"

avtoquatro::avtoquatro(float inmass)
{
    self.P_pitch=0;
        self.D_pitch=0;
        self.P_roll=0;
        self.D_roll=0;
        self.mass=0;
        self.G=9.8*self.mass;
        self.mission_ttarget={0,0,1,0,0};//режимы [арминг, взлет, автозависание,разворот, движение]

        self.mission_roll=0;
        self.error_pitch=0;
        self.error_roll=0;
        self.error_roll_previous=0;
        self.error_pitch_previous=0;
        self.mission_pitch=0;
        self.throttle_mission_avto_z=1500;
        self.throttle_mission_r=0;
        self.vector_status={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    //    self.vector_status=[[0],0,0,0,0,0,0,0,0,0,0,0,0];//d X Y Z vx vy vz health pitch roll wx wy wz
        self.dt=0.1;
        self.throttle={0,0,0,0}// левый передний, правый передний,левый задний, правый задний

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
