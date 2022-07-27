#include "bot.h"
#include "util.h"

void Bot::copiarTablero(char tablero[XTAM][YTAM],char tablero2[XTAM][YTAM]){
    for(int i = 0;i < XTAM;i++){
        for(int j = 0;j < YTAM;j++){
            tablero2[i][j]=tablero[i][j];
        }
    }
}

void Bot::comprobarVictoriaBotUser(char tablero[XTAM][YTAM]){
    Util util;
    char tableroModificado[XTAM][YTAM];
    bool ganado=false;
    char ficha[NUM_FICHAS]={'O','X'};

    for(int cont = 0;cont <NUM_FICHAS;cont++){
        for(int i = 0;i < XTAM && !ganado;i++){
            for(int j = 0;j < YTAM && !ganado;j++){
                if(tablero[i][j]==' '){
                    copiarTablero(tablero,tableroModificado);
                    tableroModificado[i][j]=ficha[cont];
                    if(util.terminado(tableroModificado)){
                        tableroModificado[i][j]='O';
                        ganado=true;
                        copiarTablero(tableroModificado,tablero);
                    }
                }
            }
        }
    }
}

void Bot::hazLoTuyo(char tablero[XTAM][YTAM]){
    comprobarVictoriaBotUser(tablero);
}