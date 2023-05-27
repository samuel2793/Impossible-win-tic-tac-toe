#ifndef _TBOARD_H_
#define _TBOARD_H_

#include <iostream>
#include <string>

using namespace std;

class TBoard
{
    private:
        int tamFila, tamCol;
        char tablero[100][100];
    public:
        TBoard();
        TBoard(int, int);
        TBoard(const TBoard&);
        ~TBoard();
        void setTamFila(int);
        void setTamCol(int);
        int getTamFila();
        int getTamCol();
        bool isFull();
        bool isEmpty();
        bool isWinner(char);
    
    friend ostream& operator<<(ostream&, const TBoard&);
};

#endif
