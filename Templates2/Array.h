#pragma once

#include <algorithm>
#include <string>
#include <cassert>
template <typename T> class Array {
private:
  T *arr;
  int current = 0;
  int size;

public:
  Array(int size = 256) : arr(new T[size]), size(size) {}
  Array(std::initializer_list<T> init) {
    size = 256;
    arr = new T[size];
    std::copy(init.begin(), init.end(), arr);
    current = init.size();
  }
  ~Array() {
    if (arr)
      delete[] arr;
    size = 0;
  }

  void push_back(const T &obj) { arr[current++] = obj; }

  void push_back(T &&obj) { arr[current++] = obj; }

  T &operator[](const size_t i) {
    assert(i >= (size_t)current);
    return arr[i];
  }

  constexpr T sum() const {
    if (size == 0)
      return 0;
    if (size == 1)
      return arr[0];
    if (size == 2)
      return std::max(arr[0], arr[1]);
    T max = arr[0];
    for (int i = 0; i < size; i++) {
      if (arr[i] > max) {
        max = arr[i];
      }
    }
    return max;
  }
};