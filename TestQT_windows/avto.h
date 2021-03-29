#ifndef AVTO_H
#define AVTO_H
#include <string.h>
#include <vector>
class avtopilot {
public:
  avtopilot(float inmass);

  float G = 9.8;
  float mass;

  std::vector<int> mission_ttarget = {
      0, 0, 1, 0, 0}; //режимы [арминг, взлет, автозависание,разворот, движение]
  std::vector<float> vector_status;
  float dt;
  float throttle[4] = {0, 0, 0, 0};
  // левый передний, правый передний,левый задний, правый задний
  // 7---6
  //
  // 5---4

  std::vector<float> F_avto(std::vector<float> vector1);
};

#endif // AVTO_H
