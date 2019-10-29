//file for bot turns...
//img of class 2 notes on strategy will be uploaded
//including randomization
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

    b->alterBoard(type, qty);

    return 1;
}