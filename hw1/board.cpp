#include "board.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//constructor
board::board()
{
    //set number of each object in an array
    numOf[HEA] = 3;
    numOf[DIA] = 7;
    numOf[SPA] = 5;
}

board::~board()
{
}
/*
* function alters the board based on:
* t = type
* n = number of ones to flip
*/
int board::alterBoard(int t, int n)
{
    int i = numOf[t];
    //cout << "entered board" << endl;
    if (i == 0 || ((i - n) < 0)) //if the number left of type is 0 or removing the number specified would make it less than 0
    {
        cout << "quanity not within correct range" << endl;
        return 0;
    }
    else
    {
        //cout << "board altered" << endl;
        numOf[t] -= n;
        return 1;
    }
}
/*
to be called whever printing board to terminal... (done after moves)
*/
void board::printBoard()
{
    int numHEA = numOf[HEA];
    int numDIA = numOf[DIA];
    int numSPA = numOf[SPA];

    cout << "    "; //set spaces for first line
    for (int i = 0; i < 3; i++)
    {
        if (i == 1)
        {
            cout << endl
                 << "   "; //next and set spaces for second line
        }

        if (numHEA > 0)
        {
            cout << SYM_HEA << " ";
            numHEA--;
        }
        else
        {
            cout << SYM_HEA_f << " ";
        }
    }
    cout << endl
         << "  "; //next and set spaces for third line
    for (int i = 0; i < 7; i++)
    {
        if (i == 3)
        {
            cout << endl
                 << " "; //next and set spaces for fourth line
        }
        if (numDIA > 0)
        {
            cout << SYM_DIA << " ";
            numDIA--;
        }
        else
        {
            cout << SYM_DIA_f << " ";
        }
    }
    cout << endl; //next and set spaces for fifth line
    for (int i = 0; i < 5; i++)
    {
        if (numSPA > 0)
        {
            cout << SYM_SPA << " ";
            numSPA--;
        }
        else
        {
            cout << SYM_SPA_f << " ";
        }
    }
    cout << endl;
}
/*
Function calculates the number left of the type specified
*/
int board::numLeft(int type)
{
    if (0 <= type && type <= 2)
    {
        return numOf[type];
    }
    else
    {
        return -1;
    }
}
//checks to see if board is empty
int board::isEmpty()
{
    return (numLeft(HEA) == 0 && numLeft(DIA) == 0 && numLeft(SPA) == 0);
}

