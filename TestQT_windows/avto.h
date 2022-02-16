#ifndef AVTO_H
#define AVTO_H
#include <string.h>
#include <vector>
class avtopilot {
public:
  // avtopilot(float inmass);

  // левый передний, правый передний,левый задний, правый задний
  // 7---6
  //
  // 5---4

  virtual std::vector<float> F_avto(std::vector<float> vector1);
  ~avtopilot();
};

#endif // AVTO_H
