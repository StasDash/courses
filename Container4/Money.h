#pragma once
#include <sstream>
#include <cmath>
#include <locale>
#include <iomanip>

class Money {
private:
  double value;

public:
  Money(double val = 0.0) : value(val) {}
  Money operator+(Money &other) { return Money(this->value + other.value); }
  Money operator-(Money &other) { return Money(this->value - other.value); }

  Money operator*(double other) { return Money(this->value * other); }
  Money operator/(double other) { return Money(this->value / other); }

  Money operator+(double other) = delete;
  Money operator-(double other) = delete;
  Money operator*(Money other) = delete;
  Money operator/(Money other) = delete;
  std::string toString() const {
    std::stringstream ret;
    ret.imbue(std::locale(""));
    ret << "$" << std::fixed << std::setprecision(2) << value;
    std::string theret = ret.str();
    for (char &c : theret) {
      if (c == ',')
        c = '.';
    }
    return theret;
  }
  friend std::ostream &operator<<(std::ostream &cout, const Money &m) {
    cout << m.toString();
    return cout;
  }
};