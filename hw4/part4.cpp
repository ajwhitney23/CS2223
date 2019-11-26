#include <cstdlib>
#include <iostream>
using namespace std;
//            Vault: 1  2   3   4   5   6   7   8
int board[8][8] = {{89, 70, 73, 83, 90, 22, 44, 92},  //row7
                   {46, 23, 99, 77, 10, 42, 1, 72},   //row6
                   {85, 52, 27, 5, 94, 91, 82, 62},   //row5
                   {22, 93, 68, 11, 56, 63, 49, 35},  //row4
                   {13, 78, 48, 19, 78, 11, 90, 94},  //row3
                   {31, 5, 63, 10, 32, 40, 14, 13},   //row2
                   {73, 38, 24, 49, 18, 6, 40, 74},   //row1
                   {79, 71, 18, 20, 34, 51, 93, 65}}; //row0

int tempPath[8]; //stores the most precious path [6, 7...] (add 1 to get vault #)
//GOAL: collect the highest value after going through every row.

//searh above given row and column finding the highest next element
int searchAbove(int row, int column)
{
    int col; //temp column to store into array
    int value = 0; //value to return
    if(column == 0) //check if against left wall
    {
        for (int i = 0; i < 2; i++)
        {
            switch (i)
            {
            case 0:
                if (board[row - 1][column] > value)//search above
                {
                    value = board[row - 1][column];
                    col = column;
    
                }
                break;
            case 1:
                if (board[row - 1][column+1] > value)//search to the right
                {
                    value = board[row - 1][column+1];
                    col = column+1;
                }
                break;
            default:
                exit(-1);
                break;
            }
        }
    }
    else if(column == 7) //check if against right wall
    {
        for (int i = 0; i < 2; i++)
        {
            switch (i)
            {
            case 0:
                if (board[row - 1][column - 1] > value)//search to the left
                {
                    value = board[row - 1][column -1];
                    col = column - 1;
                }
                break;
            case 1:
                if (board[row - 1][column] > value)//search above
                {
                    value = board[row - 1][column];
                    col = column;
                }
                break;
            default:
                exit(-1);
                break;
            }
        }
    }
    else {
        for (int i = 0; i < 3; i++)
        {
            switch (i)
            {
            case 0:
                if (board[row - 1][column - 1] > value)//search to the left
                {
                    value = board[row - 1][column - 1];
                    col = column - 1;
                }
                break;
            case 1:
                if (board[row - 1][column] > value)//search above
                {
                    value = board[row - 1][column];
                    col = column;
                }
                break;
            case 2:
                if (board[row - 1][column + 1] > value)//search to the right
                {
                    value = board[row - 1][column];
                    col = column + 1;
                }
                break;
            default:
                exit(-1);
                break;
            }
        }
    }
    tempPath[row - 1] = col; //store next column in array
    return value; //return value of that column
}
/*
row and column is current row/column 
total is current total
returns the total
*/
int nextMove(int row, int column, int total)
{
    int newTotal = total; //keep total
    if (row == 0) //done making new moves
    {
        return newTotal;
    }
    else //make new moves
    {
        newTotal = newTotal + searchAbove(row, column); //search the row above 
    }
    return nextMove(row - 1, tempPath[row - 1], newTotal); //need to find way to set next column
}

int main(int argc, char **argv)
{
    //create final array to be printed
    int finalArray[8];
    //start with the first possible path
    tempPath[7] = 0;
    int n = nextMove(7, 0, board[7][0]);
    //move tempPath into finalArray for first iteration
    for (int i = 0; i < 8; i++)
    {
        finalArray[i] = tempPath[i];
    }
    int max = 0; //max of temp
    for (int i = 0; i < 8; i++)
    {
        max = max + board[i][tempPath[i]];
    }
    int max2 = 0; //max of current highest
    for (int i = 0; i < 8; i++)
    {
        max2 = max2 + board[i][finalArray[i]];
    }
    //go through rest of row0, column j as starting points
    for (int j = 1; j < 8; j++)
    {
        tempPath[7] = j; //set first as j
        nextMove(7, j, board[7][j]); //go through rest of moves
        max = 0; //rest max to 0
        for (int i = 0; i < 8; i++) //find max of new tempPath
        {
            max = max + board[i][tempPath[i]];
        }
        if (max > max2) //if new max > old, replace it
        {
            max2 = max; 
            for (int i = 0; i < 8; i++) //move it into final
            {
                finalArray[i] = tempPath[i];
            }
        }
    }
    cout << "Bilbo Started his journey on tile : " << (finalArray[7]+1) << endl; //find where bilbo started
    cout << "This was the path he took: " << endl; //print path he took
    int num = 0;
    for (int i = 0; i < 8; i++)
    {
        cout << "row: " << 9 - (i + 1) << ", column: " << (finalArray[i] + 1) << ", value: " << board[i][finalArray[i]] << endl;
        num = num + board[i][finalArray[i]];
    }
    cout << "Total number of gems he collected: " << num << endl; //print total
    cout << "The King hid the Arkenstone in Vault " << (finalArray[0]+1) << endl; //print final destination
}