#pragma once
#include <iostream>

template <typename T> class Array {
private:
  T *data;
  int m, n;

public:
  Array(int m, int n) : data(new T[m * n]), m(m), n(n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        data[i * n + j] = i * n + j - 32 * 16;
      }
    }
  }
  ~Array() { delete data; }
  friend std::ostream &operator<<(std::ostream &cout, Array &arr) {
    for (int i = 0; i < arr.n; i++) {
      for (int j = 0; j < arr.m; j++) {
        cout << arr.data[i * arr.n + j] << " ";
      }
      cout << std::endl;
    }
    return cout;
  }

  friend void dostuff(std::ostream &cout, Array &arr) {
    for (int i = 0; i < arr.n; i++) {
      int sum = 0;
      for (int j = 0; j < arr.m; j++) {
        sum += arr.data[i * arr.n + j];
        if (arr.data[i * arr.n + j] < 0) {
          sum = -1;
          break;
        }
      }
      if (sum > 0) {
        cout << i + 1 << ": " << sum << std::endl;
      }
    }
  }
};