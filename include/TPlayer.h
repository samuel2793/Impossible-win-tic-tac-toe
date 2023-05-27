#ifndef _TPLAYER_H_
#define _TPLAYER_H_

#include <iostream>
#include <string>
#include "TBoard.h"

using namespace std;

class TPlayer{

    private:
        string name;
        char symbol;
    public:
        TPlayer();
        TPlayer(string, char);
        TPlayer(const TPlayer&);
        ~TPlayer();
        void setName(string);
        void setSymbol(char);
        string getName();
        char getSymbol();
        void play(TBoard&);
        void play(TBoard&, int, int);
        
    friend ostream& operator<<(ostream&, const TPlayer&);

};

#endif