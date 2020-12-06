#pragma once
#include <string.h>
#include <memory>
#include <iostream>

class zastringo {
private:
  char *data;
  int length;

public:
  zastringo() : length(0), data(nullptr) {}

  zastringo(const char *ptr) {
    length = strlen(ptr);
    data = (char *)calloc(1, (length + 1) * sizeof(char));
    if (!data) {
      throw "OutOfMemory";
    }
    strncpy(data, ptr, length);
  }

  ~zastringo() {
    length = 0;
    if (!data)
      free(data);
  }
  zastringo &operator=(const char *ptr) {
    int newlength = strlen(ptr);
    if (data)
      free(data);
    data = (char *)calloc(1, (newlength + 1) * sizeof(char));
    if (!data)
      throw "OutOfMemory";
    strncpy(data, ptr, newlength);
    this->length = newlength;
    return *this;
  }

  zastringo &operator=(const zastringo &b) {
    length = b.length;

    free(data);
    data = (char *)calloc(1, (length + 1) * sizeof(char));
    if (!data)
      throw "OutOfMemory";

    strncpy(data, b.data, length);
    return *this;
  }

  friend std::ostream &operator<<(std::ostream &cout,
                                  const zastringo &student) {
    cout << student.data;
    return cout;
  }

  friend std::istream &operator>>(std::istream &cin, zastringo &student) {
    char *data = (char *)malloc(256 * sizeof(char));
    cin.getline(data, 256, '\n');
    student = data;
    return cin;
  }

  constexpr int dostuff() {
    bool anySpace = false;
    int times = 0;

    for (int i = 0; i < length; i++) {
      if (data[i] == ' ') {
        anySpace = true;
      }
      if (anySpace && data[i] == ',') {
        times++;
        data[i] = '!';
      }
    }
    return times;
  }
};