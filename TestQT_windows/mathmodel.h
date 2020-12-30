#ifndef MATHMODEL_H
#define MATHMODEL_H
#include <string.h>

class mathmodel
{
public:
    mathmodel(float  X_come[]);
    float t0,t1;
    float*  X_for_analiz; // вектор для анализа
    float* X; // вектор состояния матмодели
    void write_result(); // запись результата
    float* rightpart(float t); // правые части диференциальных уравнений модели
    float* DU(float t);// интегратор
    float analiz_vector(float  X_came_for_analiz[],float t_come); // процедура анализа полученного вектора
    float* U(float t);// функция расчета управляющей силы
    //   float* f(float t);//




};

#endif // MATHMODEL_H








