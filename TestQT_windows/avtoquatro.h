#ifndef AVTOQUATRO_H
#define AVTOQUATRO_H
#include <avto.h>
#include <string.h>
class avtoquatro: public avtopilot
{
public:
    avtoquatro(float inmass);

            float P_pitch;
            float D_pitch;
            float P_roll;
            float D_roll;
        //    float mass;
        //    float G;
        //    float mission_ttarget=[0,0,1,0,0]#режимы [арминг, взлет, автозависание,разворот, движение]
            float mission_roll;
            float error_pitch;
            float error_roll;
            float error_roll_previous;
            float error_pitch_previous;
            float mission_pitch;
            float throttle_mission_avto_z;
            float throttle_mission_r;
            float vector_status[20] ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
       //   vector_status=[[0],0,0,0,0,0,0,0,0,0,0,0,0]#d X Y Z vx vy vz health pitch roll wx wy wz
      //     dt;
            float throttle[4]={0,0,0,0};// левый передний, правый передний,левый задний, правый задний
    // 7---6
    //
    // 5---4

            float f_Forse(float P,float D,float error, float spin); //функция PID
            float f_Pitch(float pitch,float target_pitch);// функция получения разницы сил от номинала для необходимого угла тангажа
            float  f_Roll(float roll,float target_roll);// функция получения разницы сил от номинала для необходимого угла крена
            float F_throttle_p(float read_pitch,float mission_pitch);
            float  F_throttle_r(float read_roll,float mission_roll);
            float  F_throttle_H();
            void mission_stabilizacia(float p,float tp,float r,float tr);
            float* F_avto(float vector1[]);


};

#endif // AVTOQUATRO_H
