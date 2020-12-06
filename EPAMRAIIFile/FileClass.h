#pragma once
#include <cstdlib>
#include <cstring>
#include <errno.h>
#include <iostream>
#include <string>
#include <vector>

class FileClass {
private:
  FILE *file;
  size_t filesize;

public:
  enum ACCESS { FREAD = 0x1, FWRITE = 0x2, FBINARY = 0x4 };
  FileClass() = delete;
  FileClass(std::string filename, int access) {
    std::string mode;
    if (access & 0x1) {
      mode += "r";
      if (access & 0x2)
        mode += "+";
    } else if (access & 0x2) {
      mode += "w";
    }
    if (access & 0x4) {
      mode += "b";
    }
    file = std::fopen(filename.c_str(), mode.c_str());
    if (file == 0) {
      throw std::string("File does not exist");
    }
    std::fseek(file, 0, SEEK_END);
    filesize = std::ftell(file);
    std::rewind(file);
  }
  std::vector<uint8_t> read(size_t offset, size_t size) {
    if (offset >= filesize) {
      return std::vector<uint8_t>();
    }
    if (size == -1) {
      size = filesize;
    }
    size = std::min(offset + size, filesize);
    std::vector<uint8_t> buf(size);
    fseek(file, offset, SEEK_SET);
    std::fread(buf.data(), 1, size, file);
    buf.shrink_to_fit();
    return buf;
  }
  void write(size_t offset, const std::vector<uint8_t> &v) {
    if (file == nullptr)
      return;
    if (offset == -1) {
      offset = filesize;
      filesize += v.size();
    }
    std::fseek(file, offset, SEEK_SET);
    std::fwrite(v.data(), 1, v.size(), file);
  }
  ~FileClass() {
    if (file)
      std::fclose(file);
    std::cout << "Destroyed";
  }
};
