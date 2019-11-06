#include <iostream>
#include <cstdlib>
#include <time.h>

//https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/

using namespace std;

//global variables
int grid[4][4] = {{1, 14, 14, 4}, {11, 7, 6, 9}, {8, 10, 10, 5}, {13, 2, 3, 15}};
/*
int sumRow1 = 0;
int sumRow2 = 0;
int sumRow3 = 0;
int sumRow4 = 0;
int sumCol1 = 0;
int sumCol2 = 0;
int sumCol3 = 0;
int sumCol4 = 0;
*/

//compares if any array is equal to 33
int is33(int array[4])
{
    int i;
    int sum = 0;
    int isEqual = 0;
    for (i = 0; i < 4; i++)
    {
        sum = sum + array[i];
    }
    if (sum == 33)
    {
        isEqual = 1;
    }
    return isEqual;
}

int main(int argc, int **argv)
{
    /*
    Initialize sums
    */

    /*int i;
    int temp = 0;
    for (i = 0; i < 4; i++)
    {
        sumRow1 = sumRow1 + grid[0][i];
        sumRow2 = sumRow2 + row2[i];
        sumRow3 = sumRow3 + row3[i];
        sumRow4 = sumRow4 + row4[i];
    }
    sumCol1 = row1[0] + row2[0] + row3[0] + row4[0];
    sumCol2 = row1[1] + row2[1] + row3[1] + row4[1];
    sumCol3 = row1[2] + row2[2] + row3[2] + row4[2];
    sumCol4 = row1[3] + row2[3] + row3[3] + row4[3];
    */
}