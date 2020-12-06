#pragma once
#include <cstdint>
#include <initializer_list>
#include <algorithm>
#include <iostream>

class vector {
private:
  int size;
  int current;
  int *ptr;
  auto get_min_index() const {
    int minest = INT32_MAX;
    int order = -1;
    for (int i = 0; i < current; i++) {
      if (ptr[i] < minest) {
        minest = ptr[i];
        order = i;
      }
    }
    return order;
  }
  auto get_max_index() const {
    int maxest = INT32_MIN;
    int order = -1;
    for (int i = 0; i < current; i++) {
      if (ptr[i] > maxest) {
        maxest = ptr[i];
        order = i;
      }
    }
    return order;
  }

public:
  vector(int size = 256) : size(size), ptr(new int[size]), current(0) {}
  vector(std::initializer_list<int> list) {

    if (ptr)
      throw "Vector already constructed";
    ptr = new int[256];
    size = 256;
    current = list.size();

    std::copy(list.begin(), list.end(), ptr);
  }
  ~vector() { delete[] ptr; }
  void push_back(int &v) {
    if (current < size) {
      ptr[current++] = v;
    }
  }
  auto get_avr() const {
    double sum = 0;
    for (int i = 0; i < current; i++) {
      sum += ptr[i];
    }
    return sum / current;
  }

  void sort() { std::sort(ptr, ptr + current); }

  int dostuff() const {
    int mini = get_min_index();
    int maxi = get_max_index();
    auto par = std::minmax(mini, maxi);
    int mul = 1;
    for (int i = par.first + 1; i < par.second; i++) {
      mul *= ptr[i];
    }
    return mul;
  }
  int get_min() const { return ptr[get_min_index()]; }
  int get_max() const { return ptr[get_max_index()]; }
  friend std::ostream &operator<<(std::ostream &cout, vector &v) {
    for (int i = 0; i < v.current; i++) {
      cout << v.ptr[i] << " ";
    }
    return cout;
  }
};
