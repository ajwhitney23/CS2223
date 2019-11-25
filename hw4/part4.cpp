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

/*
store a 2d array that holds the path and then the total... 
after we parse all paths, check for highest and then print out that row
*/

int hightestPath[8]; //stores the most precious path [6, 7...] (add 1 to get vault #)
//GOAL: collect the highest value after going through every row.

int findHighest(int row)
{
    int max = 0;
    int col;
    for (int i = 0; i < 8; i++)
    {
        if (board[row][i] > max)
        {
            max = board[row][i];
            hightestPath[row] = i;
        }
    }
    return max;
}

//searh above given row and column
int searchAbove(int row, int column, int total, int max, int min)
{
    int col;
    int value = 0;
    switch (min)
    {
    case 1:
        for (int i = 0; i < max; i++)
        {
            switch (i)
            {
            case 0:
                if (board[row - 1][column - 1] > value)
                {
                    value = board[row - 1][column - 1];
                    col = column - 1;
                }
                break;
            case 1:
                if (board[row - 1][column] > value)
                {
                    value = board[row - 1][column];
                    col = column;
                }
                break;
            case 2:
                if (board[row - 1][column + 1] > value)
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
        break;
    case 2:
        for (int i = 1; i < max; i++)
        {
            switch (i)
            {
            case 1:
                if (board[row - 1][column] > value)
                {
                    value = board[row - 1][column];
                    col = column;
                }
                break;
            case 2:
                if (board[row - 1][column + 1] > value)
                {
                    value = board[row - 1][column + 1];
                    col = column + 1;
                }
                break;
            default:
                exit(-1);
                break;
            }
        }
        break;
    default:
        cout << "error occured"
             << "min : " << min << endl;
        exit(-1);
        break;
    }
    hightestPath[row - 1] = col;
    return value;
}
/*
row and column is current row/column 
total is current total
returns the total
*/
int nextMove(int row, int column, int total)
{
    int newTotal = total;
    if (row == 0) //done making new moves
    {
        return newTotal; 
    }
    else
    {                    
        if (column == 7) //if all the way on right(search top left and mid)
        {
            //set max to 2
            //set starting to 1
            newTotal = newTotal + searchAbove(row, column, total, 2, 1);
        }
        else if (column == 0) //if all the way on left(mid and top right)
        {
            //set max to 3
            //starting to 2
            newTotal = newTotal + searchAbove(row, column, total, 3, 2);
        }
        else //(search top left, mid, right)
        {
            //set max to 3
            //set starting to 1
            newTotal = newTotal + searchAbove(row, column, total, 3, 1);
        }
    }
    return nextMove(row - 1, hightestPath[row - 1], newTotal); //need to find way to set next column
}

int main(int argc, char **argv)
{
    int currentTotal = findHighest(7);
    int max = nextMove(7, hightestPath[7], currentTotal);
    cout << "Bilbo Started his journey on tile : " << (hightestPath[7]+1) << endl;
    cout << "This was the path he took: " << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << "row: " << 9 - (i + 1) << ", column: " << (hightestPath[i] + 1) << ", value: " << board[i][hightestPath[i]] << endl;
    }
    max = 0;
    for (int i = 0; i < 8; i++)
    {
        max = max + board[i][hightestPath[i]];
    }
    cout << "Total number of gems he collected: " << max << endl;
    cout << "The King hid the Arkenstone in Vault " << (hightestPath[0]+1) << endl;
}