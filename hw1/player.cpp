#include "board.h"
#include "player.h"
#include <iostream>

using namespace std;

player::player(board *aBoard)
{
    board *b = aBoard;
}

player::~player()
{
    delete b;
}

int player::makeMove()
{
    int type;
    int qty;
    int temp;
    do
    {
        cout << "Enter type and quantity\nValid types and max quantity are:" << endl;
        if (temp = b->numLeft(HEA))
        {
            cout << "H: " << temp << endl; //print number of H, if any
        }
        if (temp = b->numLeft(DIA))
        {
            cout << "D: " << temp << endl; //print number of D, if any
        }
        if (temp = b->numLeft(SPA))
        {
            cout << "S: " << temp << endl; //print number of S, if any
        }
        cout << "Type: " << flush;
        cin >> type;
        cout << "\nQTY: " << flush;
        cin >> qty;

    } while ((0 <= type && type <= 2) && (b->numLeft(type) >= qty)); //if type is correct, check if number available is good

    return b->alterBoard(type, qty); //alter board
}

//