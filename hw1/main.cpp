#include <cstdlib>
#include <iostream>
#include "production.h"
#include "board.h"
//class production;

using namespace std;

int main(int argc, char *argv[])
{
    //testing code for functions... actually main will pretty much be running produciton
    /*board b;
    b.printBoard();
    b.printBoard();
    b.printBoard();
    b.printBoard();

    board bo;
    bo.printBoard();
    for (int i = 0;i<8;i++){
        if (!bo.alterBoard(DIA,1)){
            cout<<"bad move"<<endl;
        }
        bo.printBoard();

    }*/
    production p;
    if (p.gameStart())
    {
        cout << "Player WINS!" << endl;
    }
    else
    {
        cout << "Bot WINS!" << endl;
    }

    //call production to start / run game
}