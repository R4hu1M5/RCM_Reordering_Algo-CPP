#include <iostream>
#include <vector>
using namespace std;
#ifndef Matrix_H_
#define Matrix_H_

class Matrix {
protected:
  int _rows, _columns;
  std::vector<std::vector<float> > _matrix;
public:
  Matrix(){};
  ~Matrix();
  Matrix(int rows, int columns, std::vector<std::vector<float> > matrix);
  Matrix(const Matrix& matrix);

  int getRows() const {
    return _rows;
  }

  int getColumns() const {
    return _columns;
  }
  
  void setEntry(int i, int j, int value) {
    _matrix[i][j] = value;
  }

  std::vector<std::vector<float> > getMatrix() const {
    return _matrix;
  }

  std::vector<float> getRecord(int pos) const {
    std::vector<float> result;
    for(int i=0;i<_columns;i++)
      result.push_back(_matrix[pos][i]);
    return result;
  }

  std::vector<float> getVariable(int pos) const {
    std::vector<float> result;
    for(int i=0;i<_rows;i++)
      result.push_back(_matrix[i][pos]);
    return result;
  }

  float getEntry(int i,int j) const {
    return _matrix[i][j];
  }

  void operator = (const Matrix& matrix);

  friend std::ostream& operator << (std::ostream& os,Matrix& matrix);
};

#endif
