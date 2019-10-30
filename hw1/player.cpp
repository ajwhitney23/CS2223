#include "board.h"
#include "player.h"
#include <iostream>
#include <cstdlib>

using namespace std;

player::player()
{
}

player::~player()
{
}

int player::makeMove(board *b)
{
    int type;
    char typeS;
    int qty;
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
    if (h)
    {
        cout << "H: " << h << endl; //print number of H, if any
    }
    if (d)
    {
        cout << "D: " << d << endl; //print number of D, if any
    }
    if (s)
    {
        cout << "S: " << s << endl; //print number of S, if any
    }
    int loop = 0;
    while (loop < 10)
    {
        cout << "Type: ";
        cin >> typeS;
        if (typeS == 'H')
        {
            type = 0;
        }
        else if (typeS == 'D')
        {
            type = 1;
        }
        else if (typeS == 'S')
        {
            type = 2;
        }
        else
        {
            cout << "Type not valid" << endl;
            type = -1;
            loop++;
        }

        if (type != -1)
        {
            cout << "QTY: ";
            cin >> qty;
            if (b->numLeft(type) >= qty)
            {
                break;
            }
            else
            {
                cout << "QTY not in range" << endl;
                loop++;
            }
        }
    }
    if(loop == 10)
    {
        cout << "maximum number of attemps reached" << endl;
        exit(1);
    }

    return b->alterBoard(type, qty); //alter board
}