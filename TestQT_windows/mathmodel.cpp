#include "mathmodel.h"

mathmodel::mathmodel(std::vector<float> X_come) {

  X = X_come;
  X_for_analiz = X;
}

void mathmodel::write_result() {}

//  правые части
std::vector<float> mathmodel::rightpart(float t) {

  std::vector<float> dX = {0, 0, 0, 0, 0, 0, 0, 0};
  return dX;
}

// интегрирование
std::vector<float> mathmodel::DU(float t) {
  t0 = t1;
  t1 = t;
  float dt = t1 - t0;
  std::vector<float> dx;
  dx = rightpart(t);

  for (int i = 0; i < 8; i++) {

    X[i] = X[i] + dx[i] * dt;
  }

  return X;
}
//анализ вектора

std::vector<float>
mathmodel::analiz_vector(std::vector<float> X_came_for_analiz, float t_come) {
  X_for_analiz = X_came_for_analiz;
  float time_bort = t_come;
  DU(time_bort);
  std::vector<float> dx_analiz(X_came_for_analiz.size());
  for (int i = 0; i < X_came_for_analiz.size(); i++) {
    dx_analiz[i] = X_came_for_analiz[i] - X[i];
  }
  return dx_analiz;
}

/*float* mathmodel::f(float t):
    F_out=
    return F_out
*/
std::vector<float> mathmodel::U(float t) {
  std::vector<float> U_out = {0, 0, 0, 0, 0, 0, 0, 0};
  return U_out;
}
