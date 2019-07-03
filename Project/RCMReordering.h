#ifndef RCMReordering_H_
#define RCMReordering_H_
#include <iostream>
#include "SymmetricMatrix.h"
using namespace std;

class RCMReordering
{
private:
  SymmetricMatrix matrix;
  int r, c;
  queue<int> Q;
  vector<int> R;
public:
  RCMReordering(SymmetricMatrix input_matrix);
  ~RCMReordering();
  void sparsify();
  vector<float> calc_degree();
  void run_algorithm(vector<float> degree_array);
  void reverse_R();
  void RCM();
  int get_r()
  {
    return r;
  }
  int get_c()
  {
    return c;
  }
  int get_at_index(int i, int j)
  {
    return matrix.getEntry(i, j);
  }
  void set_at_index(int i, int j, int v)
  {
    matrix.setEntry(i, j, v);
  }
};

#endif
