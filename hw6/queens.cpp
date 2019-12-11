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

void placeQueen(int row, int col, int *array[])
{
    array[row][col] = 1;
}

bool isLegalPosition(int *array[], int row, int col, int n)
{
    //parse through the column checking to see how many queens are in each column, cant be more than 1
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(array[i][col])
        {
            count++;
        }
    }
    if(!count)
    {
        count = 0;
        for(int i = 0; i < n; i++)
        {
            if(array[i][col])
            {
                count++;
            }
        }
        if(!count)
        {
            count = 0;
            //check pos diag
            if(!count)
            {
                count = 0;
                //check neg diag
                if(!count)
                {
                    return true;
                }
                else{
                    return false;
                }
            }
        }
    }
    


}

int main(int argc, char **argv)
{
    int n;
    cout << "enter the size of the board" << endl;
    cin >> n;
    int array[n];
    cout << "enter the queens x postions below(one at a time): " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "x position: " << endl;
        cin >> array[i];
    }

    int *board[n];
    for(int i = 0; i<n; i++)
    {
        board[i] = (int *)malloc(n * sizeof(int));
    }

    int row;
    int col;
    
    for(int i = 0; i < n; i++)
    {
        col = array[i];
        row = i;
        bool x = isLegalPosition(board, row, col, n);
        if(x)
        {
            placeQueen(row, col, board);
        }
        else
        {
            cout << row << ", " << col << " is not legal position" << endl;
        }
    }

    free(board);
    return 0;
}