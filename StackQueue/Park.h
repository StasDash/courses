#pragma once
#include <vector>
#include <iostream>
#include "Bus.h"


class Park {
  std::vector<Bus> busatpark;
  std::vector<Bus> busatway;

public:
  void print() {
    for (const auto &b : busatpark) {
      std::cout << b << std::endl;
    }
    for (const auto &b : busatway) {
      std::cout << b << std::endl;
    }
  }

  void printPark() {
    for (const auto &b : busatpark) {
      std::cout << b << std::endl;
    }
  }
  void printWay() {
    for (const auto &b : busatway) {
      std::cout << b << std::endl;
    }
  }
  void fromPark(int number) {
    for (int i = 0; i < busatpark.size(); i++) {
      if (busatpark[i].get_number() == number) {
        busatway.push_back(busatpark[i]);
        busatpark.erase(busatpark.begin() + i);
        break;
      }
    }
  }
  void fromWay(int number) {
    for (int i = 0; i < busatway.size(); i++) {
      if (busatway[i].get_number() == number) {
        busatpark.push_back(busatway[i]);
        busatway.erase(busatway.begin() + i);
        break;
      }
    }
  }
  void addWay(Bus number, int after = 0) {
    busatway.insert(busatway.begin() + after, number);
  }
  void addPark(Bus number, int after = 0) {
    busatpark.insert(busatpark.begin() + after, number);
  }
};