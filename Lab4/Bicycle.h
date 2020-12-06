#pragma once
#include "Transport.h"
#include <iostream>

class Bicycle : public Transport {
private:
public:
  Bicycle(const float cost = 10) : Transport(cost, "Bicycle") {}
  int rings() { return 2; }
  int fuel() {
    std::cout << "legs" << std::endl;
    return 2;
  }
};
