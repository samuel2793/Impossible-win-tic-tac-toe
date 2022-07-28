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

int Bot::dondePonerla(char tablero[XTAM][YTAM]){
    char tableroPruebas[XTAM][YTAM];
    Util util;
    int max=0;    //primeros digitos la puntacion y el ultimo la posicion del 1 al 9
    copiarTablero(tablero,tableroPruebas);
    for(int i=1;i<=9;i++){
        if(tablero[util.traducir1to2(i).first][util.traducir1to2(i).second]==' '){
            tableroPruebas[util.traducir1to2(i).first][util.traducir1to2(i).second]='O';
            if(dondePonerla(tableroPruebas)/10 > max/10)
                max=dondePonerla(tableroPruebas);
        }
    }
    return max;
}

void Bot::hazLoTuyo(char tablero[XTAM][YTAM]){
    Util util;
    int pos;
    comprobarVictoriaBotUser(tablero);
    pos=dondePonerla(tablero)%10;
    tablero[util.traducir1to2(pos).first][util.traducir1to2(pos).second]='O';
}