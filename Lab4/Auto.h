#pragma once
#include "Transport.h"
#include <iostream>

class Auto : public Transport {
private:
public:
  Auto(const float cost = 50) : Transport(cost, "Auto") {}
  int rings() { return 4; }
  int fuel() {
    std::cout << "40kilolitre" << std::endl;
    return 40000;
  }
};
