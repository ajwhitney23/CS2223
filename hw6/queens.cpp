#include <cstdlib>
#include <iostream>
using namespace std;


int isTrue[4] = {3, 1, 4, 2};
int isFalse[4] = {1, 2, 3, 4};

/*
void make2DArray(int array[], int n)
{
    int array[n][n];
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            if ((k + 1) == array[j])
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
*/

void placeQueen(int row, int col, int array[])
{

}

bool isLegalPosition(int array[], int row, int col, int n)
{
    //parse through each column checking to see how many queens are in each column, cant be more than 1
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (array[j][i])
            {
                count++;
            }
        }
        if (count >= 2)
        {
            return false;
        }
    }
    //parse through each row checking to see how many queens are in each row, cant be more than 1
    for(int i = 0; i < n; i++)
    {
        int count = -1;
        for(int j = 0; j < n; j++)
        {
            if(array[i][j])
            {
                count++;
            }
        }
        if(count)
        {
            return false;
        }
    }
    //find way to iterate through and check diag.
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {

        }
    }
    


}

int main(int argc, char **argv)
{
    int n;
    int array[n];
    int row;
    int col;

    for(int i = 0; i < n; i++)
    {
        col = array[i];
        row = i;
        int x = isLegalPosition(board, row, col, n);
        if(x)
        {
            placeQueen(row, col);
        }
        else
        {
            cout << row << ", " << col << " is not legal position" << endl;
        }
    }

    if (x)
    {
        cout << "it is a legal position" << endl;
    }
    if (!x)
    {
        cout << "it is not a legal position" << endl;
    }
    return 0;
}