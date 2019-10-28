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

int production::gameStart()
{
    int whoFirst = 0;
    cout << "Welcome to the game!" << endl;
    //user goes on odd num, AI goes on even numbers
    do
    {
        cout << "Enter '1' if you would like to go first or '0' if you would like the AI to make the first move" << endl;
        cin >> whoFirst;
    } while (whoFirst != 1 || whoFirst != 0);

    board b;
    player aPlayer(&b); //initialize player
    bot aBot(&b);       //intialize bot

    turn = whoFirst;    //set turn to the proper start
    while (turn != 999) //while game is still active (to terminal set turn to 999)
    {
        switch (turn % 2) //alternate turns
        {
        case 1:
            cout << "---------PLAYER--------------------" << endl;
            b.printBoard();         //before print
            if (aPlayer.makeMove()) //player move
            {
                cout << "error occured" << endl;
                exit(1);
                break;
            }
            b.printBoard(); //after print
            if (b.isEmpty())
            {
                return 1; //player win
            }
            turn++; //add to turn
            break;

        case 0:
            cout << "---------BOT-----------------------" << endl;
            b.printBoard();      //before print
            if (aBot.makeMove()) //bot move
            {
                cout << "error occured" << endl;
                exit(1);
                break;
            }
            b.printBoard(); //after print
            if (b.isEmpty())
            {
                return 0; //bot win
            }
            turn++; //add to turn
            break;

        default:
            cout << "error occured" << endl;
            exit(1);
            break;
        }
    }
}
