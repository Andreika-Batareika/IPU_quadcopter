#ifndef MATHMODEL_QUATRO_H
#define MATHMODEL_QUATRO_H
#include <mathmodel.h>

class mathmodel_quatro :public mathmodel
{


public:
    float   a;
    float       h1;
     float      h;
     float      g;
     float      L;
        float    mass;
     float      L_perpendikular;
     float      Ix;
     float      Iy;
     float      Iz;
     float      Ir;
     float      w1; // левый передний
      float     w2; // правый передний
      float     w3; // левый задний
      float     w4; // правый задний
      float     u1; // управляющие вертикальное
      float     u2; // управление на крен
      float     u3; // управление на тангаж
      float     u4; // управление на курс
      float     Q;
     float      d;
     float      b;
     float      l;
    mathmodel_quatro(float X_come[], float mass);
  void   DU(float dt);
  void  B(float t);
  void  U(float t);

 void   U_signal();

};

#endif // MATHMODEL_QUATRO_H
