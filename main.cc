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

void turnoJugador(char tablero[XTAM][YTAM]){
    Util util;
    char pos='a';
    do{
        cout<<"Donde la ponemos master? (Introduce un numero del 1 al 9): ";
        cin>>pos;
    }while(!util.dentro(tablero,pos));
    tablero[util.traducir(pos).first][util.traducir(pos).second]='X';
}

void turnoBot(char tablero[XTAM][YTAM]){
    Bot bot;
    bot.hazLoTuyo(tablero);
}


int main()
{   
    Util util;
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
    mostrarTablero(tablero);
    do{
        turnoJugador(tablero);
        mostrarTablero(tablero);
        if(!util.terminado(tablero)){
            turnoBot(tablero);
            mostrarTablero(tablero);
        }
    }while(!util.terminado(tablero));

    mostrarTablero(tablero);
    cout<<"SUERTE A LA PROXIMA"<<endl;

    return 0;
}
