#include <iostream>
#include <bits/stdc++.h>
#include "RCMReordering.h"
using namespace std;

RCMReordering::RCMReordering(SymmetricMatrix input_matrix): matrix(input_matrix)
{
  r = matrix.getRows();
  c = matrix.getColumns();
}

RCMReordering::~RCMReordering()
{}

void RCMReordering::sparsify()
{
  for(int i=0; i<r; i++)
  {
    for(int j=0; j<c; j++)
    {
      if(matrix.getEntry(i, j) < 0.75)
      {
        matrix.setEntry(i, j, 0.0);
      }
      else
      {
        matrix.setEntry(i, j, 1.0);
      }
    }
  }
}

vector<float> RCMReordering::calc_degree()
{
  vector<float> degree_array;
  float temp;
  for(int i=0; i<r; i++)
  {
    temp = 0;
    for(int j=0; j<c; j++)
    {
      if(i != j)
      {
        temp += matrix.getEntry(i, j);
      }
    }
    degree_array.push_back(temp);
  }
  return degree_array;
}

void RCMReordering::run_algorithm(vector<float> degree_array)
{
  vector<float> temp_degree;
  for(int i=0; i<degree_array.size(); i++)
  {
    temp_degree.push_back(degree_array.at(i));
  }
  vector<float>::iterator least_degree;
  least_degree = min_element(degree_array.begin(), degree_array.end());

  int dist = distance(degree_array.begin(), least_degree);
  R.push_back(dist);
  temp_degree.at(dist) = (float)r + 1.0;

  map<float, int, less<float>> degree_map;
  for(int i=0; i<degree_array.size(); i++)
  {
    if(matrix.getEntry(dist, i) != 0.0 && i != dist)
    {
      degree_map.insert(make_pair(degree_array.at(i), i));
    }
  }

  map<float, int>::iterator iter;
  for(iter = degree_map.begin(); iter != degree_map.end(); iter++)
  {
    Q.push((*iter).second);
    degree_map.erase(iter);
  }

  int front = Q.front();
  Q.pop();
  while(!(Q.empty()))
  {
    if(find(R.begin(), R.end(), front) == R.end())
    {
      R.push_back(front);
      temp_degree.at(front) = (float)r + 1.0;
      for(int i=0; i<degree_array.size(); i++)
      {
        if(matrix.getEntry(front, i) != 0 && i != front)
        {
          degree_map.insert(make_pair(degree_array.at(i), i));
        }
      }
      for(iter = degree_map.begin(); iter != degree_map.end(); iter++)
      {
        Q.push((*iter).second);
        degree_map.erase(iter);
      }
    }
    front = Q.front();
    Q.pop();
  }
  if(R.size() != r)
  {
    run_algorithm(temp_degree);
  }
}

void RCMReordering::reverse_R()
{
  reverse(R.begin(), R.end());
}

void RCMReordering::RCM()
{
  vector<float> degree_array = calc_degree();
  sparsify();
  run_algorithm(degree_array);
  reverse_R();
  vector<int>::iterator it;
  for(it = R.begin(); it != R.end(); it++)
  {
    cout << *it << " ";
  }
}
