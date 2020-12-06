#pragma once
#include <string>
#include <iostream>
class Human {
private:
  std::string first_name, last_name, father_name;
  int day, month, year;
  std::string sex;

public:
  int get_month() const { return month; }
  int get_age() const { return day + month * 30 + year * 365; }
  std::string get_sex() const { return sex; }
  const std::string &get_lastname() const { return last_name; }
  friend std::istream &operator>>(std::istream &in, Human &h) {
    in >> h.first_name >> h.last_name >> h.father_name;
    in >> h.day >> h.month >> h.year;
    in >> h.sex;
    return in;
  }
  friend std::ostream &operator<<(std::ostream &out, const Human &h) {
    out << h.first_name << " " << h.last_name << " " << h.father_name << " ";
    out << h.day << " " << h.month << " " << h.year << " ";
    out << h.sex << std::endl;
    return out;
  }
  static bool byAge(const Human &a, const Human &b) {
    return a.get_age() < b.get_age();
  }
};