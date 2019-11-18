#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int standard[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

int bubblesort(int array[], int length)
{
    int inv = 0, swap = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
                swap = 1;
                inv++;
            }
        }
        if (swap != 0)
        {
            swap = 0;
        }
        else
        {
            break;
        }
    }

    return inv;
}

void printArray(int array[], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cout << "Inversions: " << bubblesort(standard, 10) << endl;
    }
    else if (argc == 2 || argc == 3)
    {
        int n = atoi(argv[1]);
        int array[n];
        for (int i = 0; i < n; i++)
        {
            array[i] = ((rand() % n) * (rand() % n)) + 1;
        }
        if (argc == 3)
        {
            cout << "Intial array: " << endl;
            printArray(array, n);
            cout << "Inversions: " << bubblesort(array, n) << endl;
            cout << "Sorted array: " << endl;
            printArray(array, n);
        }
        else
        {
            cout << "Inversions: " << bubblesort(array, n) << endl;
        }
    }
    else
    {
        cout << "./fast <(int) size of array> [print flag, any int]" << endl;
    }
    return 0;
}