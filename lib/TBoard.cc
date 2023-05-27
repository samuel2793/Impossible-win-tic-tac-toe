#include "TBoard.h"

TBoard::TBoard(){
    tamFila = 0;
    tamCol = 0;
    tablero[tamFila][tamCol];
    clear();
}

TBoard::TBoard(int tamFila, int tamCol){
    this->tamFila = tamFila;
    this->tamCol = tamCol;
    tablero[tamFila][tamCol];
    clear();
}

TBoard::TBoard(const TBoard& board){
    tamFila = board.tamFila;
    tamCol = board.tamCol;
    tablero[tamFila][tamCol];
    clear();
    for (int i = 0; i < tamFila; i++){
        for (int j = 0; j < tamCol; j++){
            tablero[i][j] = board.tablero[i][j];
        }
    }
}

TBoard::~TBoard(){
    tamFila = 0;
    tamCol = 0;
    clear();
}

void TBoard::setTamFila(int tamFila){
    this->tamFila = tamFila;
}

void TBoard::setTamCol(int tamCol){
    this->tamCol = tamCol;
}

int TBoard::getTamFila(){
    return tamFila;
}

int TBoard::getTamCol(){
    return tamCol;
}

bool TBoard::isFull(){
    for (int i = 0; i < tamFila; i++){
        for (int j = 0; j < tamCol; j++){
            if (tablero[i][j] == ' '){
                return false;
            }
        }
    }
    return true;
}

bool TBoard::isEmpty(){
    for (int i = 0; i < tamFila; i++){
        for (int j = 0; j < tamCol; j++){
            if (tablero[i][j] != ' '){
                return false;
            }
        }
    }
    return true;
}

bool TBoard::isWinner(char player){
    // Horizontal
    for (int i = 0; i < tamFila; i++){
        for (int j = 0; j < tamCol; j++){
            if (!(j+1 >= tamCol || j+2 >= tamCol)){
                if (tablero[i][j] == player && tablero[i][j+1] == player && tablero[i][j+2] == player){
                    return true;
                }
            }
        }
    }
    // Vertical
    for (int i = 0; i < tamFila; i++){
        for (int j = 0; j < tamCol; j++){
            if (!(i+1 >= tamCol || i+2 >= tamCol)){
                if (tablero[i][j] == player && tablero[i+1][j] == player && tablero[i+2][j] == player){
                    return true;
                }
            }
        }
    }
    // Diagonal
    for (int i = 0; i < tamFila; i++){
        for (int j = 0; j < tamCol; j++){
            if (!(i+1 >= tamCol || i+2 >= tamCol) && !(j+1 >= tamCol || j+2 >= tamCol)){
                if (tablero[i][j] == player && tablero[i+1][j+1] == player && tablero[i+2][j+2] == player){
                    return true;
                }
            }
        }
    }
    return false;
}

void TBoard::clear(){
    for (int i = 0; i < tamFila; i++){
        for (int j = 0; j < tamCol; j++){
            tablero[i][j] = ' ';
        }
    }
}

ostream& operator<<(ostream& os, const TBoard& board){
    for (int i = 0; i < board.tamFila; i++){
        for (int j = 0; j < board.tamCol; j++){
            if (i == 0 && j == 0){
                for (int k = -1; k <= board.tamCol; k++){
                    os << "-";
                }
                os << endl;
            }
            if (j == 0){
                os << "|";
            }
            os << board.tablero[i][j];
        }
        os << endl;
    }
    return os;
}

