#include "util.h"

pair<bool,char> Util::ganado(char tablero[XTAM][YTAM]){
    //HORIZONTALES
    if(tablero[0][0]==tablero[0][1] && tablero[0][0]==tablero[0][2] && tablero[0][0]!=' ')
        return {true,tablero[0][0]};
    if(tablero[1][0]==tablero[1][1] && tablero[1][0]==tablero[1][2] && tablero[1][0]!=' ')
        return {true,tablero[1][0]};
    if(tablero[2][0]==tablero[2][1] && tablero[2][0]==tablero[2][2] && tablero[2][0]!=' ')
        return {true,tablero[2][0]};
    
    //VERTICALES
    if(tablero[0][0]==tablero[1][0] && tablero[0][0]==tablero[2][0] && tablero[0][0]!=' ')
        return {true,tablero[0][0]};
    if(tablero[0][1]==tablero[1][1] && tablero[0][1]==tablero[2][1] && tablero[0][1]!=' ')
        return {true,tablero[0][1]};
    if(tablero[0][2]==tablero[1][2] && tablero[0][2]==tablero[2][2] && tablero[0][2]!=' ')
        return {true,tablero[0][2]};

    //DIAGONALES
    if(tablero[0][0]==tablero[1][1] && tablero[0][0]==tablero[2][2] && tablero[0][0]!=' ')
        return {true,tablero[0][0]};
    if(tablero[0][2]==tablero[1][1] && tablero[0][2]==tablero[2][0] && tablero[0][2]!=' ')
        return {true,tablero[0][2]};
    

    return {false,'N'};
}

pair<int,int> Util::traducir1to2(char pos){
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

char Util::traducir2to1(char x,char y){
    char pos[2]={x,y};
    char pos2;
    switch(pos[0]){
        case '0':
            switch(pos[1]){
                case '0':
                    pos2='1';
                    break;
                case '1':
                    pos2='2';
                    break;
                case '2':
                    pos2='3';
                    break;
            }
            break;
        case '1':
            switch(pos[1]){
                case '0':
                    pos2='4';
                    break;
                case '1':
                    pos2='5';
                    break;
                case '2':
                    pos2='6';
                    break;
            }
            break;
        case '2':
            switch(pos[1]){
                case '0':
                    pos2='7';
                    break;
                case '1':
                    pos2='8';
                    break;
                case '2':
                    pos2='9';
                    break;
            }
            break;
    }
    return pos2;
}

bool Util::lleno(char tablero[XTAM][YTAM]){
    bool lleno=true;
    for (int i = 0;i < XTAM;i++){
        for (int j = 0;j<YTAM;j++){
            if(tablero[i][j]==' ')
                lleno=false;
        }
    }
    return lleno;
}

bool Util::dentro(char tablero[XTAM][YTAM],char pos){
    int posX=traducir1to2(pos).first,posY=traducir1to2(pos).second;
    if(posX<XTAM && posY<YTAM && posX>=0 && posY>=0){
        if(tablero[posX][posY]==' ')
            return true;
        else
            return false;
    }else return false;
}

char Util::comprobarTurno(char tablero[XTAM][YTAM]){
    int user=0,ia=0;
    for(int i=1;i<=9;i++){
        if(tablero[traducir1to2(i+'0').first][traducir1to2(i+'0').second]==FICHA_USER)
            user++;
        else if(tablero[traducir1to2(i+'0').first][traducir1to2(i+'0').second]==FICHA_IA)
            ia++;
    }

    if(user>ia)
        return FICHA_IA;
    else if(user<ia)
        return FICHA_USER;
    else
        return FICHA_FIRST;
    
}