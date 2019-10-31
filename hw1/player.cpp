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
    int type;     //type to be flipped
    string typeS; //type in string format
    int qty;      //number to be flipped
    //number of hearts, diamonds, spades
    int h = b->numLeft(HEA);
    int d = b->numLeft(DIA);
    int s = b->numLeft(SPA);

    //ask user what they would like to do
    cout << "Enter type and quantity\nValid types and max quantity are:" << endl;
    //each if checks if there are still moves available for the item
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
    //loop to check if valid move if reaches 10 attempts that failed, program ends
    int loop = 0;
    while (loop < 10)
    {
        cout << "Type: ";
        cin >> typeS;
        cin.clear();
        if (typeS == "H")
        {
            type = 0;
        }
        else if (typeS == "D")
        {
            type = 1;
        }
        else if (typeS == "S")
        {
            type = 2;
        }
        else
        {
            cout << "Type not valid" << endl;
            typeS = "";
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
                qty = -1;
                loop++;
            }
        }
    }
    if (loop == 10)
    {
        cout << "maximum number of attemps reached" << endl;
        exit(1);
    }

    return b->alterBoard(type, qty); //alter board
}