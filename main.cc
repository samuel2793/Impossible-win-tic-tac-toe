#include <iostream>
#include "bot.h"

using namespace std;


void mostrarTablero(char tablero[3][3]){
    for(int i = 0;i < XTAM;i++){
        for(int j = 0;j < YTAM;j++){
            if(j==0)
                cout<<"-------"<<endl;
            cout<<"|"<<tablero[i][j];
            if(j==YTAM-1)
                cout<<"|";
        }
        cout<<endl;
    }
    cout<<"-------"<<endl;
}

pair<int,int> traducir(char pos){
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

bool dentro(char tablero[XTAM][YTAM],char pos){
    int posX=traducir(pos).first,posY=traducir(pos).second;
    if(posX<XTAM && posY<YTAM && posX>=0 && posY>=0){
        if(tablero[posX][posY]==' ')
            return true;
        else
            return false;
    }else return false;
}

void turnoJugador(char tablero[XTAM][YTAM]){
    char pos='a';
    do{
        mostrarTablero(tablero);
        cout<<"Donde la ponemos master? (Introduce un numero del 1 al 9): ";
        cin>>pos;
    }while(!dentro(tablero,pos));
    tablero[traducir(pos).first][traducir(pos).second]='X';
}

void turnoBot(char tablero[XTAM][YTAM]){
    Bot bot;
    bot.hazLoTuyo(tablero);
}

bool terminado(char tablero[XTAM][YTAM]){
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

int main()
{   
    char tablero[XTAM][YTAM]{
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };
    string aux="ouyea";
    do{
        cout<<"PREPARADO PARA EMPEZAR? (pulsa enter)"<<endl;
        getline(cin,aux);
    }while(aux!="");
    cout<<"VAMOS"<<endl;
    
    do{
        turnoJugador(tablero);
        if(!terminado(tablero))
            turnoBot(tablero);
    }while(!terminado(tablero));

    mostrarTablero(tablero);
    cout<<"SUERTE A LA PROXIMA"<<endl;

    return 0;
}
