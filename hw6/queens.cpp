#include <cstdlib>
#include <iostream>
using namespace std;

#define BOARD_SIZE 4

int isTrue[BOARD_SIZE] = {3, 1, 4, 2};
int isFalse[BOARD_SIZE] = {1, 2, 3, 4};
int board[BOARD_SIZE][BOARD_SIZE];


void make2DArray(int array[])
{
    int array[BOARD_SIZE][BOARD_SIZE];
    for(int j = 0; j < BOARD_SIZE; j++)
    {
        for(int k = 0; k < BOARD_SIZE; k++)
        {
            if((k+1) == array[j])
            {
                board[j][k] = 1;
            }
            else
            {
                board[j][k] = 0;   
            }
        }
    }
}

bool isLegalPosition(int array[BOARD_SIZE][BOARD_SIZE], int n)
{
    
    return true;
}




int main(int argc, char** argv)
{

    int x = isLegalPosition(board, BOARD_SIZE);
    if(x)
    {
        cout << "it is a legal position" << endl;
    }
    if(!x)
    {
        cout << "it is not a legal position" << endl;
    }
    return 0;
}