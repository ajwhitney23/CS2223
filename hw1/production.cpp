#include "production.h"
#include <iostream>
#include <cstdlib>
#include "board.h"
#include "player.h"
#include "bot.h"
#include <iostream>

using namespace std;

production::production()
{
    turn = 0;
}

production::~production()
{
}

int production::gameStart()
{
    int whoFirst = 0;                       //initialize local variables
    cout << "Welcome to the game!" << endl; //welcome screen
    //users goes on 1, bot goes on 0
    int loop = 0;
    while (loop < 10) //while loop ensures that correct input is selected, if not after certain amt of attempts terminates
    {
        cout << "Enter '1' if you would like to go first or '0' if you would like the AI to make the first move" << endl;
        cin >> whoFirst;
        if ((whoFirst > 1) || (whoFirst < 0)) //check if input not correct
        {
            cout << "You have entered an incorrect number, please try again." << endl;
            loop++;
        }
        else //if is correct breaks loop
        {
            break;
        }
    }
    if (loop == 10) //checks how long loop went
    {
        cout << "maximum number of attempts reached" << endl;
        exit(1);
    }
    //initialize board, board pointer, player, and bot
    board b = board();
    board *bp = &b;
    player aPlayer;
    bot aBot;

    turn = whoFirst;  //set turn to the proper start
    int isWinner = 0; //set that there isnt winner
    while (!isWinner) //should run until someone wins
    {
        switch (turn % 2) //alternate turns
        {
        case 1:
            cout << "---------PLAYER--------------------" << endl;
            cout << "Board before: " << endl;
            cout << endl;
            b.printBoard();            //print board
            if (!aPlayer.makeMove(bp)) //player move error check
            {
                cout << "error occured" << endl;
                exit(1);
                break;
            }
            cout << endl;
            cout << "Board after: " << endl;
            cout << endl;
            b.printBoard(); //print after move
            if (b.isEmpty()) //check to see if player won
            {
                return 1; //player win
            }
            //way to slow down program for user
            cout << endl;
            cin.ignore();
            cout << "Press Enter to continue..." << endl;
            cin.get();
            turn++; //add to turn
            break;

        case 0:
            cout << "---------BOT-----------------------" << endl;
            cout << "Board before: " << endl;
            cout << endl;
            b.printBoard();         //print board
            if (!aBot.makeMove(bp)) //bot move error check
            {
                cout << "error occured" << endl;
                exit(1);
                break;
            }
            cout << endl;
            cout << "Board after: " << endl;
            cout << endl;
            b.printBoard();  //print after
            if (b.isEmpty()) //check to see if bot won
            {
                return 0; //bot win
            }
            cout << endl;
            cout << "Press Enter to continue..." << endl;
            cin.get();
            
            turn++; //add to turn
            break;

        default: //should only occur w/ error
            cout << "error occured" << endl;
            exit(1);
            break;
        }
    }
    return -1; //error would occur for this to return
}
