#include "Matrix.h"
#include "RawData.h"
#include <vector>
#include <iostream>

RawData::RawData(int rows, int columns, std::vector<std::vector<float>> matrix) : Matrix(rows,columns,matrix){}

RawData::RawData(const RawData& rawdata) : Matrix(rawdata){}

RawData::~RawData() {
}
