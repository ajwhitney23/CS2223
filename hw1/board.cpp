#include "board.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//constructor
board::board()
{
    numOf[HEA] = 3;
    numOf[DIA] = 7;
    numOf[SPA] = 5;
}

board::~board()
{
    //comment
}
/*
* t = type
* n = number of ones to flip
*/
int board::alterBoard(int t, int n)
{
    if (numOf[t] == 0 || (numOf[t] - n < 0))
    {
        return 0;
    }
    else
    {
        numOf[t] -= n;
        return 1;
    }
}
/*
to be called whever printing board to terminal... (done after moves)
*/
void board::printBoard()
{
    //redunant
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
            numHEA -= 1;
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
            numDIA -= 1;
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
            numSPA -= 1;
        }
        else
        {
            cout << SYM_SPA_f << " ";
        }
    }
    cout << endl;
}