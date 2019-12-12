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

int isLegalPosition(int *array[], int row, int col, int n)
{
    //parse through the column checking to see how many queens are in each column, cant be more than 1
    for (int i = 0; i < n; i++)
    {
        if (array[i][col])
        {
            return 0;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) //check down and to the left
    {
        if (array[i][j])
        {
            return 0;
        }
    }
    for (int i = row, j = col; i < n && j < n; i++, j++) //check up and to the right
    {
        if (array[i][j])
        {
            return 0;
        }
    }
    for (int i = row, j = col; j >= 0 && i < n; i++, j--) //check up and to the left
    {
        if (array[i][j])
        {
            return 0;
        }
    }
    for (int i = row, j = col; j < n && i >= 0; i--, j++) //check down and to the right
    {
        if (array[i][j])
        {
            return 0;
        }
    }
    return 1;
}

//find the next legal position
int nextLegalPosition(int *array[], int row, int col, int n)
{
    if (col == -1)
    {
        cout << "col = -1" << endl;
        col = 0;
        cout << col << endl;
    }
    if (!isLegalPosition(array, row, col, n))
    {
        col = 0;
        while ((!isLegalPosition(array, row, col, n)) && (col < (n - 1)))
        {
            col++;
        }
    }
    if (isLegalPosition(array, row, col, n))
    {
        return col;
    }
    else
    {
        return -1;
    }
}

void clearRow(int *array[], int row, int n)
{
    for (int i = 0; i < n; i++)
    {
        array[row][i] = 0;
    }
}

//TODO: recursive function that branches per row to find first legal position
//clear row if solution not found and we backtrack
int makeMove(int *array[], int row, int n)
{
    if (row >= n)
    {
        return 1; //we recursed past the end of the board, return 1 for successful
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            int legal = isLegalPosition(array, row, i, n);
            if (legal)
            {
                placeQueen(row, i, array);
                int result = makeMove(array, row + 1, n);
                if (result == 1)
                {
                    return 1; //on good result, we're bouncing out completely
                }
                else
                {
                    clearRow(array, row, n); //on bad result, clear the row and iterate
                }
            }
        }

        //if control flow reaches here, we didn't find a legal position for current row
        //in that case, return 0 and recursion will take care of the rest
        return 0;
    }

    /*
    if (row >= n)
    {
        return 1; //we recursed past the end of the board, return 1 for successful
    }
    int col;
    if (userInput[row] != -1) //user input hasnt been placed yet
    {
        col = userInput[row]; //place user input
        userInput[row] = -1;
    }
    else //user input has been placed or user didnt input one
    {
        for (int i = 0; i < n; i++)
        {
            if (array[row][i]) //if queen is already placed, get spot and set row to 0
            {
                col = i;
            }
            array[row][i] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int temp;
        temp = nextLegalPosition(array, row, col, n);
        if (temp == -1) //no legal moves left
        {
            return 0; //we found no legal moves on this path
        }
        else
        {
            //place at next legal position and go next row
            placeQueen(row, temp, array);
            int result = makeMove(array, row + 1, n, userInput);
            if (result =)
        }
    }
    int temp;
    temp = nextLegalPosition(array, row, col, n);
    if (temp == -1) //no legal moves left
    {
        return 0; //we found no legal moves on this path
    }
    else
    {
        //place at next legal position and go next row
        placeQueen(row, temp, array);
        int result = makeMove(array, row + 1, n, userInput);
        if (result =)
    }
    */
}

void initializeBoard(int *array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            array[i][j] = 0;
        }
    }
}

void printBoard(int *array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char **argv)
{
    int n;
    cout << "enter the size of the board" << endl;
    cin >> n;
    int input[n];
    cout << "enter the queens x postions below(one at a time): " << endl;
    cout << "NOTE: if you do not wish to place a queen type 0!!!" << endl;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " row column position: " << endl;
        cin >> temp;
        if (temp)
        {
            temp = temp - 1;
            input[i] = temp;
        }
        else
        {
            input[i] = -1;
        }
    }

    int *board[n];
    for (int i = 0; i < n; i++)
    {
        board[i] = (int *)malloc(n * sizeof(int));
    }

    int row;
    int col;
    int p = atoi(argv[1]);
    /*
    if(argc == 2)
    {
        p = atoi(argv[1]);
    }
    else
    {
        p = 0;
    }
    */
    if (p == 1)
    {
        for (int i = 0; i < n; i++)
        {
            col = input[i];
            row = i;
            if (col != -1)
            {
                int x = isLegalPosition(board, row, col, n);
                if (x)
                {
                    placeQueen(row, col, board);
                    cout << row << ", " << col << " is a legal position" << endl;
                }
                else
                {
                    cout << row << ", " << col << " is not a legal position" << endl;
                }
            }
        }
    }
    if (p == 2)
    {
        for (int i = 0; i < n; i++)
        {
            row = i;
            col = nextLegalPosition(board, row, input[i], n);
            if (col != -1)
            {
                placeQueen(row, col, board);
                cout << "Placing queen at: " << row << " " << col << endl;
            }
            else
            {
                cout << "No legal position found at: " << row << " " << col << endl;
            }
        }
    }
    if (p == 3)
    {
        n = 100;
        int *secondBoard[n];
        for (int i = 0; i < n; i++)
        {
            secondBoard[i] = (int *)malloc(n * sizeof(int));
        }
        for (int i = 4; i < n; i++)
        {
            initializeBoard(secondBoard, n);
            makeMove(secondBoard, 0, i);
            cout << i << endl;
            printBoard(secondBoard, i);
        }
        for (int i = 0; i < n; i++)
        {
            free(board[i]);
        }
    }
    if (p == 0)
    {
        cout << "Usage: ./queens <partnum>" << endl;
        cout << "<partnum> = 1 or 2 or 3... etc" << endl;
    }
    for (int i = 0; i < n; i++)
    {
        free(board[i]);
    }
    return 0;
}