#include "FileHandler.h"
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

FileHandler::FileHandler(std::string filename) {
  _filename = filename;
}

std::vector<std::vector<float>> FileHandler::readFile(int n) {
  std::ifstream myfile;
  myfile.open(_filename);

  std::string s;
  bool check=false;
  int j = 0;int count=0;
  std::vector<std::vector<float> > v;
  while(getline(myfile,s)){
    char p[s.size()+1];
    strcpy(p,s.c_str());
    char *token = strtok(p,",");
    std::vector<float> temp;
    int i = 1;
    while(token != NULL){
      if(check){
        if(i <= n)
              {}
        else
          temp.push_back(stod(std::string(token)));
      }
      else{}
      token = strtok(NULL,",");
      i++;
    }
    if(check)
      v.push_back(temp);
    else
      {}
    check =true;

    j++;
    count++;
  }
  return v;
}
