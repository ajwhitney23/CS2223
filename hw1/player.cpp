#include "board.h"
#include "player.h"
#include <iostream>
#include <cstdlib>

using namespace std;

player::player(board *aBoard)
{
    board *b = aBoard;
}

player::~player()
{
    delete b;
}

int player::makeMove(board *b)
{
    int type;
    char typeS;
    int qty;
    int temp;
    int h = b->numLeft(HEA);
    int d = b->numLeft(DIA);
    int s = b->numLeft(SPA);
    /*
    do
    {
        cout << "Enter type and quantity\nValid types and max quantity are:" << endl;
        if ((temp = b->numLeft(HEA)))
        {
            cout << "H: " << temp << endl; //print number of H, if any
        }
        if ((temp = b->numLeft(DIA)))
        {
            cout << "D: " << temp << endl; //print number of D, if any
        }
        if ((temp = b->numLeft(SPA)))
        {
            cout << "S: " << temp << endl; //print number of S, if any
        }
        cout << "Type: " << flush;
        cin >> type;
        cout << "\nQTY: " << flush;
        cin >> qty;

    } while ((0 <= type && type <= 2) && (b->numLeft(type) >= qty)); //if type is correct, check if number available is good
    */
    cout << "Enter type and quantity\nValid types and max quantity are:" << endl;
    cout << "H: " << h << endl;
    cout << "D: " << d << endl;
    cout << "S: " << s << endl;
    cout << "Type: ";
    cin >> typeS;
    switch (typeS)
    {
    case 'H':
        type = 0;
        break;
    
    case 'D':
        type = 1;
        break;
    case 'S':
        type = 2;
        break;
    
    default:
        cout << "Type not valid" << endl;
        exit(1);
        break;
    }
    cout << "\nQTY: ";
    cin >> qty;

    return !(b->alterBoard(type, qty)); //alter board
}
