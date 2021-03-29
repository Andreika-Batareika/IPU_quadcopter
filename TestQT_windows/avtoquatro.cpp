#include "avtoquatro.h"
#include <avto.h>

avtoquatro::avtoquatro(float inmass) : avtopilot(inmass) {
  P_pitch = 0;
  D_pitch = 0;
  P_roll = 0;
  D_roll = 0;
  mass = 0;
  G = 9.8 * mass;

  mission_roll = 0;
  error_pitch = 0;
  error_roll = 0;
  error_roll_previous = 0;
  error_pitch_previous = 0;
  mission_pitch = 0;
  throttle_mission_avto_z = 1500;
  throttle_mission_r = 0;

  //    self.vector_status=[[0],0,0,0,0,0,0,0,0,0,0,0,0];//d X Y Z vx vy vz
  //    health pitch roll wx wy wz
  dt = 0.1;
  //   throttle={0,0,0,0}// левый передний, правый передний,левый задний, правый
  //   задний
}

float avtoquatro::f_Forse(float P, float D, float error,
                          float spin) //функция PID
{
  return P * error + D * spin;
}

float avtoquatro::f_Pitch(
    float pitch, float target_pitch) // функция получения разницы сил от
                                     // номинала для необходимого угла тангажа
{
  error_pitch_previous = error_pitch;
  error_pitch = target_pitch - pitch;
  float spin_pitch = (error_pitch - error_pitch_previous) / dt;

  return f_Forse(P_pitch, D_pitch, error_pitch, spin_pitch);
}
float avtoquatro::f_Roll(
    float roll, float target_roll) // функция получения разницы сил от номинала
                                   // для необходимого угла крена
{
  error_roll_previous = error_roll;
  error_roll = target_roll - roll;
  float spin_roll = (error_roll - error_roll_previous) / dt;
  return f_Forse(P_roll, D_roll, error_roll, spin_roll);
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

float avtoquatro::F_throttle_H() // функция для вычисления мощности  двигатеоей
                                 // для поддержания заданной высоты
{}

void avtoquatro::mission_stabilizacia(float p, float tp, float r,
                                      float tr) // (один из режимов автопилота)
{
  mission_pitch = 0;
  mission_roll = 0;
  float throttle_p = f_Pitch(p, tp);
  float throttle_r = f_Roll(r, tr);
  // 4 двигатель
  throttle[3] = throttle_mission_avto_z + throttle_p + throttle_r;
  //двигатель 5
  throttle[2] = throttle_mission_avto_z + throttle_p - throttle_r;
  //двигатель 6
  throttle[1] = throttle_mission_avto_z - throttle_p + throttle_r;
  //двигатель 7
  throttle[0] = throttle_mission_avto_z - throttle_p - throttle_r;
}

std::vector<float> avtoquatro::F_avto(
    std::vector<float> vector1) // функция автомитизации , обрабатывается если
                                // включен режим автопилота
{
  std::vector<float> outArray;
  vector_status = vector1;
  if (mission_ttarget[2] == 1)
    mission_stabilizacia(vector_status[12], 0, vector_status[13], 0);
  outArray[0] = this->throttle[0];
  outArray[1] = this->throttle[1];
  outArray[2] = this->throttle[2];
  outArray[3] = this->throttle[3];
  return outArray;
}
