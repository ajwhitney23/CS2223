//file for bot turns...
//img of class 2 notes on strategy will be uploaded
//including randomization
//https://cosmosmagazine.com/mathematics/how-to-win-at-nim
#include "board.h"
#include "bot.h"

bot::bot(board *aBoard)
{
    board *b = aBoard;
}

bot::~bot()
{
    delete b;
}

int bot::makeMove()
{
    int type;
    int qty;
    
    //use board to calc then execute alter board
    if (1) //if has move with winning strategy
    {
        //move made in hasWinning()
    }
    else 
    {
        //make random move
        //type = rand(typesLeft[])
        //qty =rand(numLeft(type))
    }

    b->alterBoard(type, qty);

    return 1;
}

void bot::hasWinning()
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
}