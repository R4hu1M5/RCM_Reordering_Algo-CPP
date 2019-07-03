#include <iostream>
#include <vector>
#include "Matrix.h"
#ifndef RawData_H_
#define RawData_H_

class RawData : public Matrix {
 public:
  RawData(int rows, int columns, std::vector<std::vector<float>> matrix);
  RawData(const RawData& rawdata);
  ~RawData();
};

#endif
