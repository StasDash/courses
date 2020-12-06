#pragma once
#include <string>
#include <iostream>

struct Student {
  std::string lastname;
  std::string firstname;
  int scores[3];

  friend std::ostream &operator<<(std::ostream &cout, const Student &student) {
    int i = 0;
    cout << student.firstname << " " << student.lastname << "\n";
    for (int score : student.scores) {
      cout << score << " ";
    }
    cout << "\nMiddle value: " << student.factor() << "\n";
    return cout;
  }

  friend std::istream &operator>>(std::istream &cin, Student &student) {
    cin >> student.firstname;
    cin >> student.lastname;
    for (int &score : student.scores) {
      cin >> score;
    }
    return cin;
  }

  float factor() const {
    float mida = static_cast<float>(this->scores[0] + this->scores[1] +
                                    this->scores[2]) /
                 3.0f;
    return mida;
  }

  bool operator<(const Student &b) const { return this->factor() < b.factor(); }
};