#include <cstdlib>
#include <iostream>
using namespace std;

int standard[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

int merge(int array[], int left, int mid, int right)
{
    int n1 = (mid + 1) - left; //left array stop point
    int n2 = right - mid;      //right array stop point
    int L[n1], R[n2];          //temp arrays

    for (int i = 0; i < n1; i++)
    {
        L[i] = array[left + i]; //copy into temp left
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = array[(mid + 1) + i]; //copy into temp right
    }

    int i = 0, j = 0, k = 0; //indexes for i,j in L,R and k for kount :)
    int n = left;            //keep track of array position we're merging into
    for (; i < n1 && j < n2; n++)
    {
        if (L[i] <= R[j])
        {
            array[n] = L[i];
            i++;
        }
        else
        {
            array[n] = R[j];
            j++;
            k++;
        }
    }
    for (; i < n1; i++, n++)
    {
        array[n] = L[i]; //merge rest of array
    }
    for (; j < n2; j++, n++)
    {
        array[n] = R[j]; //merge rest of array
    }
    return k;
}

int mergeSort(int array[], int left, int right)
{
    int count = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        count += mergeSort(array, left, mid);
        count += mergeSort(array, mid + 1, right);
        count += merge(array, left, mid, right);
    }
    return count;
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
        cout << "Inversions: " << mergeSort(standard, 0, 9) << endl;
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
            cout << "Inversions: " << mergeSort(array, 0, n - 1) << endl;
            cout << "Sorted array: " << endl;
            printArray(array, n);
        }
        else
        {
            cout << "Inversions: " << mergeSort(array, 0, n - 1) << endl;
        }
    }
    else
    {
        cout << "./fast <(int) size of array> [print flag, any int]" << endl;
    }
    return 0;
}
