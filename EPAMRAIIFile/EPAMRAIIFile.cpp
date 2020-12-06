#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include "FileClass.h"

int main() {
  FileClass a("EPAMRAIIFile.cpp", FileClass::FREAD | FileClass::FWRITE);
  auto v = a.read(0, 4096);
  std::cout << std::string(v.begin(), v.end()) << std::endl;
}