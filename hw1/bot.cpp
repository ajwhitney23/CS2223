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
        //make move
    }
    else 
    {
        //type random 1-3
        //qty random 1-3
    }

    b->alterBoard(type, qty);

    return 1;
}