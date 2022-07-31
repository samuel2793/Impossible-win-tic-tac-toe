#ifndef _UTIL_H_
#define _UTIL_H_

#include <iostream>
#include <vector>
using namespace std;
const int XTAM=3,YTAM=3;
const int NUM_FICHAS=2;
const char FICHA_USER='X',FICHA_IA='O';
const char FICHA_FIRST=FICHA_USER;

class Util{
  public:
    pair<bool,char> ganado(char tablero[XTAM][YTAM]);
    pair<int,int> traducir1to2(char pos);
    char traducir2to1(char x,char y);
    bool lleno(char tablero[XTAM][YTAM]);
    bool dentro(char tablero[XTAM][YTAM],char pos);
    char comprobarTurno(char tablero[XTAM][YTAM]);
};

#endif