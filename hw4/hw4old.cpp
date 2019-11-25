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

void GJEM(double array[8][9])
{
    int i;
    int temp;
    int order = 8;
    int n;
    int j;
    int k;
    for (i = 0; i < order; i++) //go through order(x1, x2, x3...)
    {
        //check if row needs to be switched(can't start w/ 0)
        if (array[i][i] == 0)
        {
            //search until i+n != 0 and is less than order
            for (n = 1; n + i < order; n++)
            {
                if (n + i != 0) //find first canidate and break for loop
                {
                    break;
                }
            }
            for (j = i, k = 0; k <= order; k++) //switch rows
            {
                temp = array[j + n][k];
                array[j + n][k] = array[j][k];
                array[j][k] = temp;
            }
        }

        for (j = 0; j < order; j++) //go through rows, wait until j is not i
        {
            if (j != i)
            {
                for (k = 0; k <= order; k++)
                {
                    array[j][k] = array[j][k] - (array[i][k] * (array[j][i] / array[i][i]));
                }
            }
        }
    }
}

void printArray(double array[8][9])
{
    int order = 8;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << array[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "-----------------------" << endl;
}

void bottom(double array[8][9])
{
    for (int k = 0; k < 8; k++)
    {
        for (int i = 0; i < 8; i++)
        {
            if (i > k)
            {
                for (int j = 0; j < 9; j++)
                {
                    //array[i][j] = (array[k][j] * inverse) + array[i][j];
                    //cout <<"before: " <<array[i][j] << endl;
                    if (j != 8)
                    {
                        array[i][j] = array[i][j] - (array[k][j] * (array[i][k] / array[k][k]));
                    }
                    if (j == 8)
                    {
                        array[i][j] = (array[k][j] * (array[i][k] * -1)) + array[i][j];
                    }

                    //cout << "after: " << array[i][j] << endl;
                }
            }
        }
    }
}

void simplify(double array[8][9])
{
    for (int i = 0; i < 8; i++)
    {
        if (array[i][i] != 0)
        {
            double temp = array[i][i];
            for (int j = 0; j < 9; j++)
            {
                array[i][j] = array[i][j] / temp;
            }
        }
    }
}

void top(double array[8][9])
{
    //row 1 = row 1 minus (row 2 * element 2)
    //row 1 = row 1 minus (row 3 * element 3)
    //... n
    //row 2 = row 2 minus (row 3 * element 3)
    //... n
    //int inverse = 0;
    for (int k = 0; k < 8; k++)
    {
        for (int i = k + 1; i < 8; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                //array[i][j] = (array[k][j] * inverse) + array[i][j];
                //cout <<"before: " <<array[i][j] << endl;
                array[k][j] = array[k][j] - (array[i][j] * array[k][i]);
                //cout << "after: " << array[i][j] << endl;
            }
        }
    }
}

void GJE(double array[8][9])
{
    bottom(array);
    printArray(array);
    simplify(array);
    printArray(array);
    top(array);
}

int main(int argc, char **argv)
{
    GJE(testArray);
    printArray(testArray);
    return 0;
}
