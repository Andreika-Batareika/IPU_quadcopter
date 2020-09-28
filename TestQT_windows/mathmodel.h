#ifndef MATHMODEL_H
#define MATHMODEL_H


class mathmodel
{
public:
   mathmodel(float  X_come[]);
  float*  X_for_analiz;
   float* X;
       void write_result();
       float* rightpart(float t);
       float* DU(float t);
       void analiz_vector(float  X_came_for_analiz[],float t_come[]);
       float* U(float t);
       float* f(float t);



}

#endif // MATHMODEL_H








