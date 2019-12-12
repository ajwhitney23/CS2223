#include <cstdlib>
#include <iostream>
using namespace std;

void placeQueen(int row, int col, int *array[])
{
    array[row][col] = 1;
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
            cout << (array[i][j] ? 'Q' : '-') << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int isLegalPosition(int *array[], int row, int col, int n)
{
    if (col >= n)
    {
        return 0;
    }
    //parse through the column checking to see how many queens are in each column, cant be more than 1
    for (int i = 0; i < n; i++)
    {
        if (array[i][col])
        {
            return 0;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) //check up and to the left
    {
        if (array[i][j])
        {
            return 0;
        }
    }
    for (int i = row, j = col; j < n && i >= 0; i--, j++) //check up and to the right
    {
        if (array[i][j])
        {
            return 0;
        }
    }
    for (int i = row, j = col; i < n && j < n; i++, j++) //check down and to the right
    {
        if (array[i][j])
        {
            return 0;
        }
    }
    for (int i = row, j = col; j >= 0 && i < n; i++, j--) //check down and to the left
    {
        if (array[i][j])
        {
            return 0;
        }
    }

    return 1;
}

int isLegalPositionOnlyUp(int *array[], int row, int col, int n)
{
    if (col >= n)
    {
        return 0;
    }
    //parse through the column checking to see how many queens are in each column, cant be more than 1
    for (int i = row; i >= 0; i--)
    {
        if (array[i][col])
        {
            return 0;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) //check up and to the left
    {
        if (array[i][j])
        {
            return 0;
        }
    }
    for (int i = row, j = col; j < n && i >= 0; i--, j++) //check up and to the right
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
        col = 0;
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
            int valid = isLegalPositionOnlyUp(array, row, i, n);
            if (valid)
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
}

int findAllSolutions(int *array[], int row, int n)
{
    if (row >= n)
    {
        printBoard(array, n);
        return 1; //we want to go down all alternate branches, so bounce back
    }
    else
    {
        int acc = 0;
        for (int i = 0; i < n; i++)
        {
            int valid = isLegalPositionOnlyUp(array, row, i, n);
            if (valid)
            {
                placeQueen(row, i, array);
                acc += findAllSolutions(array, row + 1, n);
                clearRow(array, row, n);
            }
        }

        //if control flow reaches here, we didn't find a legal position for current row
        //in that case, return 0 and recursion will take care of the rest
        return acc;
    }
}

void getInputNums(int *array[], int input[], int n)
{

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
    return;
}

int main(int argc, char **argv)
{

    int part = atoi(argv[1]);
    int n = atoi(argv[2]);
    int input[n];
    int *board[n];
    for (int i = 0; i < n; i++)
    {
        board[i] = (int *)malloc(n * sizeof(int));
    }
    int row;           //part 1 & 2
    int col;           //part 1 & 2
    int solutions = 0; //used in part 4

    switch (part)
    {
    case 1:
        getInputNums(board, input, n);
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
        break;

    case 2:
        getInputNums(board, input, n);
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
        break;

    case 3:
        //board is constrained, enter 100 to check the performance based on instructions
        for (int i = 4; i < n; i++)
        {
            initializeBoard(board, n);
            makeMove(board, 0, i);
            cout << i << endl;
            printBoard(board, i);
        }
        break;
    case 4:
        initializeBoard(board, n);
        printBoard(board, n);
        solutions = findAllSolutions(board, 0, n);
        cout << solutions << endl;
        break;

    default:
        cout << "Useage: ./queens <partNumber> <boardSize>" << endl
             << "partNumber can be an integer between 1-4" << endl;
        break;
    }
    for (int i = 0; i < n; i++)
    {
        free(board[i]);
    }
    return 0;
}