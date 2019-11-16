#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int initial[256];

void bubblesort(int arrayLength)
{
    int i;
    int j;
    int swapped = 0;
    int temp;
    int temp2;
    int numInv;
    for (i = 1; i < arrayLength; i++)
    {
        swapped = 0;
        for (j = 1; j < arrayLength; j++)
        {
            //less than or equal is no swap, making it stable
            if (initial[j] > initial[j + 1])
            {
                temp = initial[j + 1];
                temp2 = initial[j];
                initial[j] = temp;
                initial[j + 1] = temp2;
                swapped = 1;
                numInv++;
            }
        }
        if(!swapped)
        {
            break;
        }
    }
    cout << "numer of inversions: " << numInv << endl;
}

void printArray(int array[], int arrayLength)
{
    int i;
    for(i = 1; i < arrayLength; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}


int main(int argc, char **argv)
{
    int i;
    int j;
    for (j = 1; j < argc; j++)
    {
        initial[j] = atoi(argv[j]);
    }
    initial[argc] = 999999;
    printArray(initial, argc);
    bubblesort(argc);
    printArray(initial, argc);
    
}