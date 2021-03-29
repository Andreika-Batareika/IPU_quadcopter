#ifndef MATHMODEL_H
#define MATHMODEL_H
#include <string.h>
#include <vector>
class mathmodel {
public:
  mathmodel(std::vector<float> X_come);
  float t0, t1;
  std::vector<float> X_for_analiz; // вектор для анализа
  std::vector<float> X; // вектор состояния матмодели
  void write_result();  // запись результата
  std::vector<float> rightpart(float t);
  // правые части диференциальных уравнений модели
  std::vector<float> DU(float t);
  // интегратор
  std::vector<float> analiz_vector(std::vector<float> X_came_for_analiz,
                                   float t_come);
  // процедура анализа полученного вектора
  std::vector<float> U(float t); // функция расчета управляющей силы
                                 //   float* f(float t);//
};

#endif // MATHMODEL_H
