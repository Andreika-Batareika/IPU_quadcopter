#include "mathmodel_quatro.h"
#include <mathmodel.h>
#include <math.h>
#include <cmath>



mathmodel_quatro::mathmodel_quatro(float X_come[8], float come_mass):mathmodel(X_come){
   a=0.4;
       h1=0.4;
       h=0.15;
       g=9.8;
     L=0.20;
      mass=come_mass;
     L_perpendikular=L*cos(3.14/4.0);
      Ix=1.0/12.0*mass*a*a;
       Iy=1.0/12.0*mass*a*a;
       Iz=1.0/12.0*mass*(a*a+h1*h1);
     Ir=0.0001;
    w1=0; // левый передний
       w2=0; // правый передний
       w3=0; // левый задний
       w4=0; // правый задний
       u1=0; // управляющие вертикальное
       u2=0; // управление на крен
      u3=0; // управление на тангаж
       u4=0; // управление на курс
     Q=0;
       d=0;
     b=0;
     l=0;
 //  TMath_model.__init__(X_come)
   X = X_come; //X Y Z Vx Vy Vz speed_heating speed_pitch speed_roll  heating pitch roll








  k1=l/Ix;
  k2=l/Iy;
  k3=l/Iz;
  C1=(Iy-Iz)/Ix;
  C2=-Ir/Iz;
  C3=(Iz-Ix)/Iy;
  C4=-Ir/Iy;
  C5=(Ix-Iy)/Iz;
}



// интегратор
//void mathmodel_quatro::DU(float dt)
// {
//
//   X=X+rightpart(t)*dt;
// }

/*
float** mathmodel_quatro::B(float t){
   -(cos(  X[11])*sin(  X[10])*cos(  X[9])+sin(  X[11])*sin(  X[9]))/  mass;
   -(cos(  X[11])*sin(  X[10])*sin(  X[9])+sin(  X[11])*cos(  X[9]))/  mass;
   -(cos(  X[11])*cos(  X[10]))/  mass;
   B_out=np.matrix();
   return B_out;
}


*/



     float* mathmodel_quatro::rightpart(float t)// правые части диференциальных уравнений модели
{

  float Ux=cos(  X[11])*sin(  X[10])*cos(X[9])+sin(  X[11])*sin(  X[9]);
 float  Uy=(cos(  X[11])*sin(  X[10])*sin(  X[9])+sin(  X[11])*cos(  X[9]));
     X[8];
     X[6]*  X[7]*C1+C2*  X[7]*  Q+k1*  u2;
     X[7];
     X[6]*  X[8]*C3+C4*  X[7]*  Q+k2*  u3;
     X[6];
     X[6]*  X[7]*C5+k3*  u4;
     X[5];
     g-(cos(  X[8])*cos(  X[7]))*  u1/  mass;
     X[3];
   Ux*1/  mass*  u1;
     X[4];
   Uy*1/  mass*  u1;
  float F_out[8*8];
   return F_out;
 }


     //вычисления   ..
float* mathmodel_quatro::U_signal(){
     u1=  d*(  w1*  w1+  w2*  w2+  w3*  w3+  w4*  w4);
     u2=  d*(  w1*  w1-  w2*  w2+  w3*  w3-  w4*  w4);
     u3=  d*(  w1*  w1+  w2*  w2-  w3*  w3-  w4*  w4);
     u4=  d*(-  w1*  w1+  w2*  w2+  w3*  w3-  w4*  w4);
     Q=  w1+  w2+  w3+  w4;
}

float* mathmodel_quatro::U(float t)// функция расчета управляющей силы
{}
