#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#ifndef FileHandler_H
#define FileHandler_H

class FileHandler {
private:
  std::string _filename;
public:
  FileHandler(){}
  ~FileHandler(){}
  FileHandler(std::string filename);
  std::vector<std::vector<float>> readFile(int n);

  void setFileName(std::string filename) {
    _filename = filename;
  }

  std::string getFileName() {
    return _filename;
  }
};

#endif
