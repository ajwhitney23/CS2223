#include <cstdlib>
#include <iostream>
#include "production.h"
#include "board.h"
class production;

using namespace std;
int main(int argc, char *argv[])
{
    board b;
    b.printBoard();
    assert(b.alterBoard(HEA,3));
    b.printBoard();
    assert(b.alterBoard(DIA,4));
    b.printBoard();
    assert(!b.alterBoard(SPA,7));
    b.printBoard();

    board bo;
    bo.printBoard();
    for (int i = 0;i<8;i++){
        if (!bo.alterBoard(DIA,1)){
            cout<<"bad move"<<endl;
        }
        bo.printBoard();

    }
    
}