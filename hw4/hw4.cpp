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
                if (n + i != 0)//find first canidate and break for loop
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
        //go through rows
        for (j = 0; j < order; j++)
        {
            if (j != i )
            {
                double num = array[j][i] / array[i][i];

                for(k = 0; k <= order; k++){
                    array[j][k] = array[j][k] - (array[i][k] * num);
                }
            }
        }
    }
}



void printArray(double array[8][9]) 
{ 
    int order = 8;
    for (int i = 0; i < order; i++) 
    { 
        for (int j = 0; j <= order; j++)
        {  
          cout << array[i][j] << " "; 
        }
        cout << endl; 
    } 
}

int main(int argc, char **argv)
{
    GJEM(testArray);
    printArray(testArray);
    return 0;
}
