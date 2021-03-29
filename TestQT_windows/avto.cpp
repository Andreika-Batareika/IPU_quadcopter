#include "avto.h"
#include <vector>
avtopilot::avtopilot(float inmass) {

  this->mass = inmass;
  G = 9.8 * mass;

  dt = 0.1;
}
std::vector<float> avtopilot::F_avto(std::vector<float> vector1) {}
