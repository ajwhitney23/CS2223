#include <cstdlib>
#include <iostream>
#include <ctime>
#include "production.h"
#include "board.h"
//class production;

using namespace std;

int main(int argc, char *argv[])
{
    srand(time(NULL));
    //create production
    production p;
    if (p.gameStart()) //start game if games returns 1 player wins else bot wins
    {
        cout << "Bot: you have defeated me, I will not let this happen again!" << endl;
        cout << "Player WINS!" << endl;
    }
    else
    {
        cout << "Bot: HAHA I have beaten you, better luck next time!" << endl;
        cout << "Bot WINS!" << endl;
    }
}