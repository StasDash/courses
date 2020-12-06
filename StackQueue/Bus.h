#pragma once
#include <string>
#include <iostream>

class Bus {
  std::string er;
  std::int32_t number;
  int32_t way;

public:
  int get_number() { return number; }
  Bus(std::string er, int32_t number, int32_t way)
      : er(er), number(number), way(way) {}
  friend std::ostream &operator<<(std::ostream &cout, const Bus &bus) {
    cout << bus.er << " " << bus.number << " " << bus.way;
    return cout;
  }
  friend std::istream &operator>>(std::istream &cin, Bus &bus) {
    cin >> bus.er >> bus.number >> bus.way;
    return cin;
  }
};