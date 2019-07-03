#include "SquareMatrix.h"
#include <iostream>
#include <vector>
#ifndef SymmetricMatrix_H_
#define SymmetricMatrix_H_

class SymmetricMatrix : public SquareMatrix {
public:
  SymmetricMatrix(int size,std::vector<std::vector<float> > matrix);
  SymmetricMatrix(const SymmetricMatrix& symmetricmatrix);
  ~SymmetricMatrix();
  vector<pair<int,int> >basic_minorder();
};

#endif
