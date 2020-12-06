#pragma once
#include <vector>
#include <iostream>

class vzastringo {
private:
  std::vector<char> str;

public:
  vzastringo() : str() {}

  vzastringo(const char const *ptr) {
    int length = strlen(ptr);
    str.resize(length + 1);
    std::copy(ptr, ptr + length, str.data());
  }

  vzastringo &operator=(const char *ptr) {
    int newlength = strlen(ptr);
    str.resize(newlength);
    std::copy(ptr, ptr + newlength, str.data());
    return *this;
  }

  vzastringo &operator=(std::vector<char> b) {
    this->str = b;
    return *this;
  }

  vzastringo &operator=(const vzastringo &b) {
    str.clear();
    str.resize(b.str.size());
    std::copy(b.str.begin(), b.str.end(), this->str.data());
    return *this;
  }

  friend std::ostream &operator<<(std::ostream &cout,
                                  const vzastringo &student) {
    cout << student.str.data();
    return cout;
  }

  friend std::istream &operator>>(std::istream &cin, vzastringo &student) {
    std::vector<char> newone(256);
    cin.getline(newone.data(), 256, '\n');
    student = newone;
    return cin;
  }
  int dostuff() {
    bool anySpace = false;
    int times = 0;
    for (char &sym : this->str) {
      if (sym == ' ') {
        anySpace = true;
      }
      if (anySpace && sym == ',') {
        times++;
        sym = '!';
      }
    }
    return times;
  }
};