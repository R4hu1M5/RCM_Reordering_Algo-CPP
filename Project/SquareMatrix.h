#include "Matrix.h"
#include <iostream>
#include <vector>
#ifndef SquareMatrix_H_
#define SquareMatrix_H_

class SquareMatrix : public Matrix {
public:
  SquareMatrix(){}
  SquareMatrix(int size,std::vector<std::vector<float> > matrix);
  SquareMatrix(const SquareMatrix& squarematrix);
  ~SquareMatrix();
};

#endif
