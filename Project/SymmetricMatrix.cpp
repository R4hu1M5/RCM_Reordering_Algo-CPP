#include "SquareMatrix.h"
#include "SymmetricMatrix.h"
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
bool isSymmetric(std::vector<std::vector<float> > matrix) {
  for(int i=0;i<matrix.size();i++)
    for(int j=0;j<matrix[0].size();j++)
      if(matrix[i][j] != matrix[j][i])
        return false;
  return true;
}

SymmetricMatrix::SymmetricMatrix(int size, std::vector<std::vector<float> > matrix) {
  if(matrix.size() == size && matrix[0].size() == size) {
    if(isSymmetric(matrix)) {
      _rows = size;
      _columns = size;
      _matrix.resize(_columns, std::vector<float>(_rows,0.0));
      for(int i=0;i<_rows;i++)
        for(int j=0;j<_columns;j++)
          _matrix[i][j] = matrix[i][j];
    }
  }
}

SymmetricMatrix::SymmetricMatrix(const SymmetricMatrix& symmetricmatrix) : SquareMatrix(symmetricmatrix) {}

SymmetricMatrix::~SymmetricMatrix() {
}

vector<pair<int,int> > SymmetricMatrix::basic_minorder()
{

std::vector<float> compute;
std::vector<pair<int,int> > v;
std::vector<int> check(_rows,0);

for(int i=0;i<_rows;i++)
{ float sum=0;
  for(int j=0;j<_rows;j++)
  {
     if(i==j){continue;}
     else{sum+=_matrix[i][j];}
  }
 compute.push_back(sum);
}

for(int i=0;i<_rows;i++)
{ float min=INT_MAX;
  int row_index;
  for(int j=0;j<_rows;j++)
  {
    if(min>compute[j] && check[j]==0){min=compute[j];row_index=j;}
  }
  pair<int,int> p;
  p=make_pair(row_index,row_index);
  v.push_back(p);
  check[row_index]=1;
  for(int j=0;j<_rows;j++)
  {
    if(check[j]!=1)
    {
      compute[j]-=_matrix[j][row_index];
    }
  }
}

return v;
}
