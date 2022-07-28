#ifndef _UTIL_H_
#define _UTIL_H_

#include <iostream>
#include <vector>
using namespace std;
const int XTAM=3,YTAM=3;
const int NUM_FICHAS=2;

class Util{
  public:
    bool terminado(char tablero[XTAM][YTAM]);
    pair<int,int> traducir1to2(char pos);
    char traducir2to1(char x,char y);
    bool dentro(char tablero[XTAM][YTAM],char pos);
};

#endif