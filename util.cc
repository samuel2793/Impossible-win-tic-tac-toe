#include "util.h"

bool Util::terminado(char tablero[XTAM][YTAM]){
    //HORIZONTALES
    if(tablero[0][0]==tablero[0][1] && tablero[0][0]==tablero[0][2] && tablero[0][0]!=' ')
        return true;
    if(tablero[1][0]==tablero[1][1] && tablero[1][0]==tablero[1][2] && tablero[1][0]!=' ')
        return true;
    if(tablero[2][0]==tablero[2][1] && tablero[2][0]==tablero[2][2] && tablero[2][0]!=' ')
        return true;
    
    //VERTICALES
    if(tablero[0][0]==tablero[1][0] && tablero[0][0]==tablero[2][0] && tablero[0][0]!=' ')
        return true;
    if(tablero[0][1]==tablero[1][1] && tablero[0][1]==tablero[2][1] && tablero[0][1]!=' ')
        return true;
    if(tablero[0][2]==tablero[1][2] && tablero[0][2]==tablero[2][2] && tablero[0][2]!=' ')
        return true;

    //DIAGONALES
    if(tablero[0][0]==tablero[1][1] && tablero[0][0]==tablero[2][2] && tablero[0][0]!=' ')
        return true;
    if(tablero[0][2]==tablero[1][1] && tablero[0][2]==tablero[2][0] && tablero[0][2]!=' ')
        return true;
    

    return false;
}

pair<int,int> Util::traducir(char pos){
    pair <int,int> pos2;
    switch(pos){
        case '1':
            pos2.first=0;
            pos2.second=0;
            break;
        case '2':
            pos2.first=0;
            pos2.second=1;
            break;
        case '3':
            pos2.first=0;
            pos2.second=2;
            break;
        case '4':
            pos2.first=1;
            pos2.second=0;
            break;
        case '5':
            pos2.first=1;
            pos2.second=1;
            break;
        case '6':
            pos2.first=1;
            pos2.second=2;
            break;
        case '7':
            pos2.first=2;
            pos2.second=0;
            break;
        case '8':
            pos2.first=2;
            pos2.second=1;
            break;
        case '9':
            pos2.first=2;
            pos2.second=2;
            break;
        default: pos2.first=-1, pos2.second=-1;
    }
    return pos2;
}

bool Util::dentro(char tablero[XTAM][YTAM],char pos){
    int posX=traducir(pos).first,posY=traducir(pos).second;
    if(posX<XTAM && posY<YTAM && posX>=0 && posY>=0){
        if(tablero[posX][posY]==' ')
            return true;
        else
            return false;
    }else return false;
}