#include "mathmodel_quatro.h"




mathmodel_quatro::mathmodel_quatro(float X_come[], float mass){
   a=0.4;
       h1=0.4;
       h=0.15;
       g=9.8;
     L=0.20;
      mass=come_mass;
     L_perpendikular=self.L*cos(3.14/4.0);
      Ix=1.0/12.0*self.mass*a*a;
       Iy=1.0/12.0*self.mass*a*a;
       Iz=1.0/12.0*self.mass*(a*a+h1*h1);
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
   X[] = X_come; //X Y Z Vx Vy Vz speed_heating speed_pitch speed_roll  heating pitch roll








  k1=self.l/self.Ix;
  k2=self.l/self.Iy;
  k3=self.l/self.Iz;
  C1=(self.Iy-self.Iz)/self.Ix;
  C2=-self.Ir/self.Iz;
  C3=(self.Iz-self.Ix)/self.Iy;
  C4=-self.Ir/self.Iy;
  C5=(self.Ix-self.Iy)/self.Iz;
}
void mathmodel_quatro::DU(float dt)
 {

   self.X=self.X+self.rightpart(t)*dt;
 }
float** mathmodel_quatro::B(float t){
   -(cos(self.X[11])*sin(self.X[10])*cos(self.X[9])+sin(self.X[11])*sin(self.X[9]))/self.mass;
   -(cos(self.X[11])*sin(self.X[10])*sin(self.X[9])+sin(self.X[11])*cos(self.X[9]))/self.mass;
   -(cos(self.X[11])*cos(self.X[10]))/self.mass;
   B_out=np.matrix();
   return B_out;
}
 f(float t){

  float Ux=cos(self.X[11])*sin(self.X[10])*cos(X[9])+sin(self.X[11])*sin(self.X[9]);
 float  Uy=(cos(self.X[11])*sin(self.X[10])*sin(self.X[9])+sin(self.X[11])*cos(self.X[9]));
   self.X[8];
   self.X[6]*self.X[7]*C1+C2*self.X[7]*self.Q+k1*self.u2;
   self.X[7];
   self.X[6]*self.X[8]*C3+C4*self.X[7]*self.Q+k2*self.u3;
   self.X[6];
   self.X[6]*self.X[7]*C5+k3*self.u4;
   self.X[5];
   self.g-(cos(self.X[8])*cos(self.X[7]))*self.u1/self.mass;
   self.X[3];
   Ux*1/self.mass*self.u1;
   self.X[4];
   Uy*1/self.mass*self.u1;
   F_out=np.matrix();
   return F_out;
 }
float* mathmodel_quatro::U(float t){
   U_out=F_thrttle;
   return U_out;
}
float* mathmodel_quatro::U_signal(){
   self.u1=self.d*(self.w1*self.w1+self.w2*self.w2+self.w3*self.w3+self.w4*self.w4);
   self.u2=self.d*(self.w1*self.w1-self.w2*self.w2+self.w3*self.w3-self.w4*self.w4);
   self.u3=self.d*(self.w1*self.w1+self.w2*self.w2-self.w3*self.w3-self.w4*self.w4);
   self.u4=self.d*(-self.w1*self.w1+self.w2*self.w2+self.w3*self.w3-self.w4*self.w4);
   self.Q=self.w1+self.w2+self.w3+self.w4;
}

