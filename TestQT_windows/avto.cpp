#include "avto.h"

avto::avto(float inmass)
{

    self.mass=inmass;
        self.G=9.8*self.mass;
        self.mission_ttarget={0,0,1,0,0}; //режимы [арминг, взлет, автозависание,разворот, движение]
        self.vector_status={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    //    self.vector_status=[[0],0,0,0,0,0,0,0,0,0,0,0,0]#d X Y Z vx vy vz health pitch roll wx wy wz
        self.dt=0.1;
        self.throttle={0,0,0,0};// левый передний, правый передний,левый задний, правый задний


}
 float* avto::F_avto(float vector1[])
 {

 }

