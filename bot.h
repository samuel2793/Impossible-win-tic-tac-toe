#ifndef _BOT_H_
#define _BOT_H_

#include <iostream>
#include <vector>
#include "util.h"
using namespace std;

class Bot{
  public:
    void copiarTablero(char tablero[XTAM][YTAM],char tablero2[XTAM][YTAM]);
    void comprobarVictoriaBotUser(char tablero[XTAM][YTAM]);
    void hazLoTuyo(char tablero[XTAM][YTAM]);
};

#endif