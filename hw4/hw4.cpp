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

void swap(int r1, int r2)
{
    if (r1 == r2)
    {
        return;
    }
    for (int i = 0; i < 9; i++)
    {
        double d = c[r1][i];
        c[r1][i] = c[r2][i];
        c[r2][i] = d;
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

void GJE()
{
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
    }
}

void REF()
{
    int lead = 0;
    int rows = 8;
    int cols = 9;

    for (int r = 1; r < rows; r++)
    {
        if (cols <= lead)
        {
            cout << "cols<=lead" << endl;
            break;
        }
        int i = r;
        while (c[i][lead] == 0)
        {
            cout << "in while" << endl;
            i++;
            if (rows == i)
            {
                i = r;
                lead++;
                if (cols == lead)
                {
                    break;
                }
            }
        }
        printArray();
        swap(i, r);
        printArray();
        if (c[r][lead] != 0)
        {
            cout << "c[r][lead]!=0" << endl;
            for (int j = 0; j < cols; j++)
            {
                c[r][j] = c[r][j] / c[r][lead];
            }
        }
        printArray();
        for (int j = 0; j < rows; j++)
        {
            if (j != r)
            {
                for (int k = 0; k < cols; k++)
                {
                    c[i][k] -= c[r][k] * c[i][lead];
                }
            }
        }
        printArray();
        lead++;
    }
}

int main(int argc, char **argv)
{
    printArray();
    REF();
    simplify();
    GJE();
    printArray();
    cout << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << "x" << i << "= " << setw(7) << c[i][8] << endl;
    }
    return 0;
}
