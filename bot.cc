#include "bot.h"
#include "util.h"

void Bot::copiarTablero(char tablero[XTAM][YTAM],char tablero2[XTAM][YTAM]){
    for(int i = 0;i < XTAM;i++){
        for(int j = 0;j < YTAM;j++){
            tablero2[i][j]=tablero[i][j];
        }
    }
}

void Bot::comprobarVictoriaBot(char tablero[XTAM][YTAM]){
    Util util;
    char tableroModificado[XTAM][YTAM];
    bool ganado=false;
    for(int i = 0;i < XTAM;i++){
        for(int j = 0;j < YTAM;j++){
            if(tablero[i][j]==' '){
                copiarTablero(tablero,tableroModificado);
                tableroModificado[i][j]='O';
                if(util.terminado(tableroModificado)){
                    
                }
            }
        }
    }
}

void Bot::hazLoTuyo(char tablero[XTAM][YTAM]){
    comprobarVictoriaBot(tablero);
}