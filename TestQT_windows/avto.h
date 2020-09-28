#ifndef AVTO_H
#define AVTO_H


class avto
{
public:
    avto();

       float G=9.8;
       float mass;

      float mission_ttarget[5] ={0,0,1,0,0};//режимы [арминг, взлет, автозависание,разворот, движение]
        float vector_status[] ;
  float dt;
 float throttle[]={0,0,0,0}; // левый передний, правый передний,левый задний, правый задний
// 7---6
//
// 5---4


  float* F_avto(float vector1[]);

};

#endif // AVTO_H
