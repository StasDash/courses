#pragma once
#include "Transport.h"
#include <iostream>

class Motorcycle : public Transport {
private:
public:
  Motorcycle(const float cost = 100) : Transport(cost, "Motorcycle") {}
  int rings() { return 2; }
  int fuel() {
    std::cout << "20litre" << std::endl;
    return 20;
  }
};