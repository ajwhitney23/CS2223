//https://www.youtube.com/watch?v=0fTSBIBD7Cs
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

//coefficients in system of linear equations
double c[8][9] = {{1, 1, 1, 1, 1, 1, 1, 1, 0},
                  {1, 2, 1, 1, 1, 1, 2, 1, 0},
                  {1, 1, 3, 1, 1, 3, 1, 1, 0},
                  {1, 1, 1, 4, 4, 1, 1, 1, 0},
                  {11, 1, 1, 1, 1, 1, 1, 1, 20},
                  {1, 1, 1, 1, -1, -1, -1, -1, 34},
                  {1, 2, 3, 4, 5, 6, 7, 8, -51},
                  {1, -1, 1, -1, 1, -1, 1, -1, -6}};

//prints array
void printArray()
{
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (j == 8)
            {
                cout << "| ";
            }
            cout << setw(10) << setprecision(4) << c[i][j];
        }
        cout << endl;
    }
}

void simplify()
{
    cout << "S" << endl;
    //scale matrix operation by inverse of diagonals
    //effectively creates leading 1's for gaussian elimination
    for (int i = 0; i < 8; i++)
    {
        if (c[i][i] != 0)
        {
            double d = c[i][i]; //divisor, used as inverse to make leading coefficients 1
            for (int j = 0; j < 9; j++)
            {
                c[i][j] = c[i][j] / d;
            }
        }
    }
}

void GE()
{
    //simplify();
    cout << "GE" << endl;
    //perform gaussian elimination to produce row echelon form

    //iterate variable columns, not columns for constants
    for (int i = 0; i < 8; i++)
    {
        //iterate all rows
        for (int j = i + 1; j < 8; j++)
        {
            double s = c[j][i] / c[i][0]; //temporary variable for scalar in pivot action
            printf("%d,%d,%f", i, j, s);
            //operate on all columns for pivot data
            //cout << "before " << s << endl;
            //printArray();
            if (isnormal(s))
            {
                cout << "normal" << endl;
                for (int k = i; k < 9; k++)
                {
                    c[j][k] += -1 * (s * c[i][k]);
                    //c[i][j] = c[i][j] - (c[k][j] * (c[i][k] / c[k][k]));
                    //c[j][k] = c[j][k] - (c[i][k] * (c[j][i] / c[i][i]));
                }
            }
            s = 0;
            //printArray();
            //cout << "after" << endl;
        }
        cout << i << endl;
        printArray();
    }
    simplify();
}

void GJE()
{
    cout << "GJE" << endl;
    //perform gauss-jordan elimination to produce reduced row echelon form
    double s; //temporary variable for scalar in pivot action
    //iterate variable columns, not columns for constants
    for (int i = 7; i >= 0; i--)
    {
        //iterate all rows
        for (int j = i - 1; j >= 0; j--)
        {

            s = c[j][i] / c[i][i];
            //operate on all columns for pivot data
            if (isnormal(s))
            {
                for (int k = 8; k >= 0; k--)
                {
                    c[j][k] += -1 * (s * c[i][k]);
                }
            }
        }

        printArray();
    }
    simplify();
}

int main(int argc, char **argv)
{
    printArray();
    GE();
    printArray();
    GJE();
    printArray();
    //GJE(testArray);
    //printArray(testArray);
    return 0;
}
