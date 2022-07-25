#include <iostream>

using namespace std;

void mostrarTablero(){
    char tablero[3][3]{
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            if(j==0)
                cout<<"-------"<<endl;
            cout<<"|"<<tablero[i][j];
            if(j==2)
                cout<<"|";
        }
        cout<<endl;
    }
    cout<<"-------"<<endl;
}

int main()
{   
    string aux="ouyea";
    do{
        cout<<"¿PREPARADO PARA EMPEZAR? (pulsa enter)"<<endl;
        getline(cin,aux);
    }while(aux!="");
    cout<<"VAMOS"<<endl;
    mostrarTablero();
    
    turnoJugador();
    turnoBot();
    

    return 0;
}
