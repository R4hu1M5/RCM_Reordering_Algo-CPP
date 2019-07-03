#include <iostream>
#include <bits/stdc++.h>
#include "RCMReordering.h"

int main(int argc, char const *argv[])
{
  int r = 3;
  vector<vector<float>> matrix;
  for(int i=0; i<3; i++)
  {
    for(int j=0; j<3; j++)
    {
      if(i == j)
        matrix[i][j] == 1;
      else
        matrix[i][j] == 0;
    }
  }
  SymmetricMatrix sm(3, matrix);
  RCMReordering rcm(sm);
  rcm.RCM();
}
