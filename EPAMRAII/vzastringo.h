#pragma once
#include <vector>
#include <iostream>
class vzastringo {
private:
  std::vector<char> str;

  vzastringo &operator=(std::vector<char> b) {
    this->str = b;
    return *this;
  }

public:
  vzastringo() : str() { std::cerr << "default constructor\n"; }

  vzastringo(const char *ptr) {
    std::cerr << "const char* constructor\n";
    int length = strlen(ptr);
    str.resize(length + 1);
    std::copy(ptr, ptr + length, str.data());
  }

  vzastringo(const vzastringo &b) {
    std::cerr << "const vzastringo& constructor\n";
    str.resize(b.str.size());
    std::copy(b.str.begin(), b.str.end(), this->str.data());
  }
  vzastringo(vzastringo &&b) noexcept {
    std::cerr << "vzastringo&& constructor\n";
    if (&b == this)
      return;
    if (&b != nullptr) {
      this->str = std::move(b.str);
      b.str.clear();
    }
  }

  vzastringo &operator=(const char *ptr) {
    std::cerr << "const char* operator=\n";
    int newlength = strlen(ptr);
    str.resize(newlength + 1);
    std::copy(ptr, ptr + newlength, str.data());
    return *this;
  }

  vzastringo &operator=(const vzastringo &b) {
    std::cerr << "const vzastringo& operator=\n";
    str.resize(b.str.size());
    std::copy(b.str.begin(), b.str.end(), this->str.data());
    return *this;
  }

  vzastringo &operator=(vzastringo &&b) noexcept {
    std::cerr << "vzastringo&& operator=\n";
    if (&b == this)
      return *this;
    if (&b != nullptr) {
      this->str = std::move(b.str);
      b.str.clear();
    }
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

  ~vzastringo() { std::cout << "Destroyed" << std::endl; }
};
