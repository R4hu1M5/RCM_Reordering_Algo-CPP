#include "Matrix.h"
#include "SquareMatrix.h"
#include <iostream>
#include <vector>

SquareMatrix::SquareMatrix(int size,std::vector<std::vector<float> > matrix) {
  if(matrix.size() == size && matrix[0].size() == size) {
    _rows = size;
    _columns = size;
    _matrix.resize(_columns, std::vector<float>(_rows,0.0));
    for(int i=0;i<_rows;i++)
      for(int j=0;j<_columns;j++)
        _matrix[i][j] = matrix[i][j];
  }
}

SquareMatrix::SquareMatrix(const SquareMatrix& squarematrix) : Matrix(squarematrix){}

SquareMatrix::~SquareMatrix() {
}
