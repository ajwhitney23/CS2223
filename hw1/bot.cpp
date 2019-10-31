//file for bot turns...
//img of class 2 notes on strategy will be uploaded
//including randomization
//https://cosmosmagazine.com/mathematics/how-to-win-at-nim
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "board.h"
#include "bot.h"

using namespace std;

bot::bot()
{
}

bot::~bot()
{
}
/*
function makes move for the bot
*/
int bot::makeMove(board *b)
{
    int type;
    int qty;

    //use board to calc then execute alter board
    if (hasWinning(b)) //if has move with winning strategy
    {
        //move made in hasWinning()
        return 1;
    }
    else
    {
        return randomFromBoard(b);
    }
}
/*
if there is a winning position on the board
*/
int bot::hasWinning(board *b)
{
    int A = b->numLeft(0); //max 3 Hearts
    int B = b->numLeft(1); //max 7
    int C = b->numLeft(2); //max 5
    int i = 0;

    if (C > (A ^ B))
    {
        //call function alterBoard to remove enough markers from C to be equal to A XOR B
        //cout << "C > (A ^ B)" << endl;
        while (b->numLeft(2) != (A ^ B))
        {
            b->alterBoard(2, 1);
            i++;

        }
        cout << "Bot is removing " << i << " Spades from the board." << endl;
        return 1;
    }
    else if (B > (A ^ C))
    {
        //call function alterBoard to remove enough markers from B to be equal to A XOR C
        //cout << "B > (A ^ C)" << endl;
        while (b->numLeft(1) != (A ^ C))
        {
            b->alterBoard(1, 1);
            i++;
        }
        cout << "Bot is removing " << i << " Diamonds from the board." << endl;
        return 1;
    }
    else if (A > (B ^ C))
    {
        //call function alterBoard to remove enough markers from A to be eual to B XOR C
        //cout << "A > (B ^ C)" << endl;
        while (b->numLeft(0) != (B ^ C))
        {
            b->alterBoard(0, 1);
            i++;
        }
        cout << "Bot is removing " << i << " Hearts from the board." << endl;
        return 1;
    }
    else
    {
        //cout << "no winning strat" << endl;
        return 0;
    }
}
/*
selects random types nad quantity to flip
*/
int bot::randomFromBoard(board *b)
{
    int t; //type
    int q; //quantity
    int n; //numleft
    int i; //index
    char* pType;

    while (true)
    {
        t = rand() % 3;    //picking type/index
        n = b->numLeft(t); //get number left
        if (n != 0)
        {
            q = (rand() % n) + 1; //get random qty
            break;
        }
    }
    //cout << t << " " << q << flush;
    switch (t)
    {
    case 0:
        cout << "Bot is removing " << q << " Hearts from the board." << endl;
        break;
    case 1:
        cout << "Bot is removing " << q << " Diamonds from the board." << endl;
        break;
    case 2:
        cout << "Bot is removing " << q << " Spades from the board." << endl;
        break;

    default:
        cout << "unknown" <<endl;
        exit(1);
        break;
    }
    return b->alterBoard(t, q);
}