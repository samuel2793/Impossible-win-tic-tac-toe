#include "bot.h"
#include "util.h"

void Bot::copiarTablero(char tablero[XTAM][YTAM],char tablero2[XTAM][YTAM]){
    for(int i = 0;i < XTAM;i++){
        for(int j = 0;j < YTAM;j++){
            tablero2[i][j]=tablero[i][j];
        }
    }
}

bool Bot::comprobarVictoriaBotUser(char tablero[XTAM][YTAM],char fichaC){
    char tableroModificado[XTAM][YTAM];
    bool ganado=false;
    char ficha[NUM_FICHAS]={FICHA_IA,FICHA_USER};

    for(int cont = 0;cont <NUM_FICHAS;cont++){
        for(int i = 0;i < XTAM && !ganado;i++){
            for(int j = 0;j < YTAM && !ganado;j++){
                if(tablero[i][j]==' '){
                    copiarTablero(tablero,tableroModificado);
                    tableroModificado[i][j]=ficha[cont];
                    if(util.ganado(tableroModificado).first){
                        tableroModificado[i][j]=fichaC;
                        ganado=true;
                        copiarTablero(tableroModificado,tablero);
                    }
                }
            }
        }
    }
    return ganado;
}

void Bot::simularUsuario(char tablero[XTAM][YTAM]){
    if(comprobarVictoriaBotUser(tablero,FICHA_USER)){}
    else{
        for(int i=1;i<=9;i++){
            if(tablero[util.traducir1to2(i+'0').first][util.traducir1to2(i+'0').second]==' ')
                tablero[util.traducir1to2(i+'0').first][util.traducir1to2(i+'0').second]=FICHA_USER;
        }
    }

}

int Bot::puntuacionPosicion(char tablero[XTAM][YTAM],char pos,int punt){
    tablero[util.traducir1to2(pos+'0').first][util.traducir1to2(pos+'0').second]=util.comprobarTurno(tablero);
    if(util.ganado(tablero).first){
        if(util.ganado(tablero).second==FICHA_USER)
            punt-=1;
        else
            punt+=1;
    }
    else if(util.lleno(tablero)){
        punt=+0;
    }
    else{
        /*for(int i=1;i<=9;i++){
            if(tablero[util.traducir1to2(i+'0').first][util.traducir1to2(i+'0').second]==' '){
                pos=i;
                break;
            }
        }*/
        //if(util.comprobarTurno(tablero)==FICHA_USER) ME DA MAL IDK WHY
            simularUsuario(tablero);
        for(int i=1;i<=9;i++){
            if(tablero[util.traducir1to2(i+'0').first][util.traducir1to2(i+'0').second]==' ')
                punt+=puntuacionPosicion(tablero,i+'0',punt);
        }
    }

    return punt;
}

int Bot::dondePonerla(char tablero[XTAM][YTAM]){
    int max=-1;
    int pos=-1;
    int nuevaPuntuacion;
    char tableroPruebas[XTAM][YTAM];
    for(int i=1;i<=9;i++){
        if(tablero[util.traducir1to2(i+'0').first][util.traducir1to2(i+'0').second]==' '){
            copiarTablero(tablero,tableroPruebas);  // tablero nuevo para cada calculo
            nuevaPuntuacion=puntuacionPosicion(tableroPruebas,i+'0',0);
            if(max<nuevaPuntuacion){
                max=nuevaPuntuacion;
                pos=i;
            }
        }
    }
    return pos;
}

void Bot::hazLoTuyo(char tablero[XTAM][YTAM]){
    char pos;
    if(!comprobarVictoriaBotUser(tablero,FICHA_IA)){
        pos=dondePonerla(tablero)+'0';
        if (pos!=-1)
            tablero[util.traducir1to2(pos).first][util.traducir1to2(pos).second]=FICHA_IA;
        else
            cout<<"aa\n";
    }
}