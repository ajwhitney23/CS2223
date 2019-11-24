//https://www.youtube.com/watch?v=0fTSBIBD7Cs
#include <cstdlib>
#include <iostream>
using namespace std;

double testArray[8][9] = {{1, 1, 1, 1, 1, 1, 1, 1, 0},
                          {1, 2, 1, 1, 1, 1, 2, 1, 0},
                          {1, 1, 3, 1, 1, 3, 1, 1, 0},
                          {1, 1, 1, 4, 4, 1, 1, 1, 0},
                          {11, 1, 1, 1, 1, 1, 1, 1, 20},
                          {1, 1, 1, 1, -1, -1, -1, -1, 34},
                          {1, 2, 3, 4, 5, 6, 7, 8, -51},
                          {1, -1, 1, -1, 1, -1, 1, -1, -6}};

void printArray()
{
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < 8; i++)
    {
        printf("%7.3f %7.3f %7.3f %7.3f %7.3f %7.3f %7.3f %7.3f | %7.3f \n",
               testArray[i][0], testArray[i][1], testArray[i][2], testArray[i][3], testArray[i][4],
               testArray[i][5], testArray[i][6], testArray[i][7], testArray[i][8]);
        //not the prettiest solution but the results are nice
    }
}

void pivot(int row, int column, int prow)
{
    double pivotRow[9]; //copy of pivoting row, which is the row that has leading 1
    for (int i = 0; i < 9; i++)
    {
        pivotRow[i] = testArray[prow][i];
    }

    double scalar = -1.0 * testArray[row][column]; //negative of item we're trying to zero
    for (int i = 0; i < 9; i++)
    {
        pivotRow[i] = pivotRow[i] * scalar; //scale the pivoting row
    }
    //when we add scaled array, should set the target to 0
    for (int i = 0; i < 9; i++)
    {
        testArray[row][i] = testArray[row][i] + pivotRow[i]; //add the two rows, set array
    }
}

void simplify()
{
    //scale matrix operation by inverse of diagonals
    //effectively creates leading 1's for gaussian elimination
    for (int i = 0; i < 8; i++)
    {
        if (testArray[i][i] != 0)
        {
            double temp = testArray[i][i];
            for (int j = 0; j < 9; j++)
            {
                testArray[i][j] = testArray[i][j] / temp;
            }
        }
    }
}

void GE()
{
    simplify(); //simplify to setup
    printArray();
    for (int k = 0; k < 9; k++)
    {
        //row we're on for the pivots
        for (int i = k + 1; i < 8; i++)
        {
            //goes to prow+1 since we're targeting stuff below 1's in the column
            for (int j = 0; j < 9; j++)
            {
                pivot(i, j, k);
            }
            printArray;
        }
    }
    simplify(); //just to maintain leading 1's. probably redundant
}

void GJE()
{
}

int main(int argc, char **argv)
{
    printArray();
    GE();
    printArray();
    //GJE(testArray);
    //printArray(testArray);
    return 0;
}
