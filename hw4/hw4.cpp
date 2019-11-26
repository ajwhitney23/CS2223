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

//swaps two rows
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

//creates diagonal 1's
void simplify()
{
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

//perform gauss-jordan elimination to produce reduced row echelon form
void GJE()
{
    //iterate variable columns, not columns for constants
    for (int i = 7; i >= 0; i--)
    {
        //iterate all rows
        for (int j = i - 1; j >= 0; j--)
        {
            double s = c[j][i] / c[i][i]; //temporary variable for scalar in pivot action
            //operate on all columns for pivot data
            if (isnormal(s))
            {
                for (int k = 8; k >= 0; k--)
                {
                    c[j][k] -= s * c[i][k];
                }
            }
        }
    }
}

void REF()
{
    //code written based on pseudocode from wikipedia, creates row echelon form (upper triangular matrix)
    //see REF.png for pseudocode
    int lead = 0; //lead column we're reducing
    int rows = 8; //number of rows
    int cols = 9; //number of columns

    for (int r = 1; r < rows; r++)
    {
        if (cols <= lead)
        {
            break;
        }
        int i = r;
        while (c[i][lead] == 0)
        {
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
        swap(i, r); //swap row i and r
        if (c[r][lead] != 0)
        {
            for (int j = 0; j < cols; j++)
            {
                c[r][j] = c[r][j] / c[r][lead];
            }
        }
        for (int j = 0; j < rows; j++)
        {
            if (j != r)
            {
                for (int k = 0; k < cols; k++)
                {
                    c[i][k] -= c[r][k] * c[i][lead]; //setting 0
                }
            }
        }
        lead++;
    }
}

int main(int argc, char **argv)
{
    cout << "before" << endl;
    printArray(); //print array before
    REF();        //reduce to row echelon form
    GJE();        //reduce to reduced row echelon form
    simplify();   //create diagonal unit matrix
    cout << "after" << endl;
    printArray(); //print array after
    cout << endl;
    int verify = 0;
    for (int i = 0; i < 8; i++)
    {
        cout << "x" << i << ": " << setw(7) << c[i][8] << endl;
        verify += c[i][8];
    }
    cout << "sum: " << verify << endl; //if the sum adds up to 0, it's likely to be at least partially correct
    return 0;
}
