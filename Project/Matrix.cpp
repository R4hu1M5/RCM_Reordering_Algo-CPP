#include "Matrix.h"
#include <iostream>
#include <vector>

Matrix::Matrix(int rows, int columns, std::vector<std::vector<float> > matrix) {
  _rows = rows;
  _columns = columns;
  _matrix.resize(_columns, std::vector<float>(_rows,0.0));
  for(int i=0;i<rows;i++)
    for(int j=0;j<columns;j++)
      _matrix[i][j] = matrix[i][j];
}

Matrix::Matrix(const Matrix& matrix) {
  _rows = matrix.getRows();
  _columns = matrix.getColumns();
  _matrix.resize(_columns, std::vector<float>(_rows,0.0));
  for(int i=0;i<_rows;i++)
    for(int j=0;j<_columns;j++)
      _matrix[i][j] = matrix.getEntry(i,j);
}

Matrix::~Matrix() {
  std::vector<std::vector<float> >().swap(_matrix);
}

std::ostream& operator << (std::ostream& os, Matrix& matrix) {
  for(int i=0;i<matrix.getRows();i++) {
    for(int j=0;j<matrix.getColumns();j++) {
      os << matrix.getEntry(i, j) << " ";
    }
    os << "\n";
  }
  return os;
}

void Matrix::operator = (const Matrix& matrix) {
  _rows = matrix.getRows();
  _columns = matrix.getColumns();
  _matrix.resize(_columns, std::vector<float>(_rows,0.0));
  for(int i=0;i<_rows;i++)
    for(int j=0;j<_columns;j++)
      _matrix[i][j] = matrix.getEntry(i,j);
}
