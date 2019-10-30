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

int bot::makeMove(board *b)
{
    int type;
    int qty;

    //use board to calc then execute alter board
    if (hasWinning(b)) //if has move with winning strategy
    {
        //move made in hasWinning()
        return 0;
    }
    else
    {
        //type = randomFromArray(b->typesLeft);
        //qty = rand(b->numLeft(type));
        return randomFromBoard(b);
    }
}

int bot::hasWinning(board *aBoard)
{
    int A;
    int B;
    int C;
    /*
    if C > (A XOR B)
    {
        call function alterBoard to remove enough markers from C to be equal to A XOR B
        return 1;
    }
    if else B > (A XOR C)
    {
        call function alterBoard to remove enough markers from B to be equal to A XOR C
        return 1;
    }
    if else A > (B XOR C)
    {
        call function alterBoard to remove enough markers from A to be eual to B XOR C
        return 1;
    }



    */
    return 0;
}

int bot::randomFromBoard(board *b)
{
    int t; //type
    int q; //quantity
    int n; //numleft
    int i; //index

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
    cout << t << " " << q << flush;
    return b->alterBoard(t, q);
}