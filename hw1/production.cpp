#include "production.h"
#include <iostream>
#include <cstdlib>
#include "board.h"
#include "player.h"
#include "bot.h"

using namespace std;

production::production()
{
    turn = 0;
}

void production::gameStart()
{
    int whoFirst = 0;
    cout << "Welcome to the game!" << endl;
    //user goes on odd num, AI goes on even numbers
    do
    {
        cout << "Enter '1' if you would like to go first or '2' if you would like the AI to make the first move" << endl;
        cin >> whoFirst;
    } while (whoFirst != 1 || whoFirst != 2);

    while (turn != 999) //while game is still active (to terminal set turn to 999)
    {
        switch (whoFirst % 2)
        {
        //user first
        case 1:
            //user turn
            break;
        //bot first
        case 0:
            //ai turn
            break;
        default:
            cout << "error occured" << endl;
            exit(1);
            break;
        }
    }
}
