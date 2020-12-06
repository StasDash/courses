#pragma once
#include <string>
#include <ostream>
class Transport {
private:
  float cost;
  std::string doe;

public:
  Transport(const float cost, std::string does) : cost(cost), doe(does) {}
  float get_cost() const { return cost; }
  friend std::ostream &operator<<(std::ostream &cout, Transport &tr) {
    cout << "Cost: " << tr.cost << " and it's a " << tr.doe;
    return cout;
  }
  virtual int rings() = 0;
  virtual int fuel() = 0;
};
