#ifndef _BOT_H_
#define _BOT_H_

#include <iostream>
#include <vector>
#include "util.h"
using namespace std;

class Bot{
  private:
    Util util;
  public:
    void copiarTablero(char tablero[XTAM][YTAM],char tablero2[XTAM][YTAM]);
    bool comprobarVictoriaBotUser(char tablero[XTAM][YTAM],char fichaC);
    void hazLoTuyo(char tablero[XTAM][YTAM]);
    int puntuacionPosicion(char tablero[XTAM][YTAM],char pos, int punt);
    int dondePonerla(char tablero[XTAM][YTAM]);
};

#endif