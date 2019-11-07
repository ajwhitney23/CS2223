#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>

//https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/

using namespace std;

//global variables
//      [r][c]
int grid[4][4] = {{1, 14, 14, 4},
                  {11, 7, 6, 9},
                  {8, 10, 10, 5},
                  {13, 2, 3, 15}};
int list[16] = {1, 14, 14, 4, 11, 7, 6, 9, 8, 10, 10, 5, 13, 2, 3, 15};
int sumTotal[133]; //{0, 4, 1} would mean the sum was 0 0 times, 1 4 times, and 2 1 time...

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

int comb4(int printFlag)
{
    int acc = 0;
    for (int i = 0; i < 13; i++)
    {
        for (int j = i + 1; j < 14; j++)
        {
            for (int k = j + 1; k < 15; k++)
            {
                for (int l = k + 1; l < 16; l++)
                {
                    if ((list[i] + list[j] + list[k] + list[l]) == 33)
                    {
                        if (printFlag)
                        {
                            printf("index: i, %2i | j, %2i | k, %2i | l,%2i \n", i, j, k, l);
                            printf("value: i, %2i | j, %2i | k, %2i | l,%2i \t(%2i)\n\n", list[i], list[j], list[k], list[l], (list[i] + list[j] + list[k] + list[l]));
                        }
                        acc++;
                    }
                }
            }
        }
    }
    return acc;
}
/*
int combN(int maxDepth, int cDepth, int indexPrev, int sumPrev, int compare)
{
    int acc = 0;
    if (maxDepth == cDepth)
    {
        for (int i = indexPrev; i < 16; i++)
        {
            if (sumPrev + list[i] == compare)
            {
                printf("%2i %2i %2i %2i\n", cDepth, indexPrev, sumPrev, compare);
                acc++;
            }
        }
    }
    else
    {
        for (int i = indexPrev; i < (16 - (maxDepth - cDepth)); i++)
        {
            acc += combN(maxDepth, 1 + cDepth, i, (sumPrev + list[i]), compare);
        }
    }
    return acc;
}
*/

void combN(int maxDepth, int cDepth, int indexPrev, int sumPrev)
{
    if (maxDepth == cDepth)
    {
        for (int i = indexPrev; i < 16; i++)
        {
            int sum = sumPrev + list[i];
            sumTotal[sum]++;
        }
    }
    else
    {
        for (int i = indexPrev; i < (16 - (maxDepth - (cDepth + 1))); i++)
        {
            combN(maxDepth, 1 + cDepth, i + 1, (sumPrev + list[i]));
        }
    }
}

int main(int argc, char *argv[])
{
    int i = 0;
    for (i = 0; i < 133; i++)
    {
        sumTotal[i] = 0;
    }
    sumTotal[0]++;

    for (i = 0; i < 16; i++)
    {
        combN(i, 0, 0, 0);
    }

    if (argc > 1)
    {

        switch ((atoi(argv[1])))
        {
        case 1:
            cout << endl
                 << "-------4.1-------" << endl
                 << endl
                 << endl;
            cout << "Number of 4-element combinations that equal 33: " << comb4(0) << endl
                 << endl;
            cout << "Proof: " << endl;
            cout << comb4(1) << endl;
            break;

        case 2:
            cout << endl
                 << "-------4.2-------" << endl
                 << endl
                 << endl;
            cout << "All combinations that equal 33: " << sumTotal[33] << endl
                 << endl;
            break;

        case 3:
            cout << endl
                 << "-------4.3-------" << endl
                 << endl
                 << endl;
            for (int w = 0; w < 133; w++)
            {
                //cout << w << " " << sumTotal[w] << endl;
                cout << sumTotal[w] << " combinations of different elements sum to " << w << endl;
            }
            break;

        case 4:
            //stuff
            break;

        default:
            cout << endl
                 << "-------4.1-------" << endl
                 << endl
                 << endl;
            cout << "Number of 4-element combinations that equal 33: " << comb4(0) << endl
                 << endl;
            cout << "Proof: " << endl;
            cout << comb4(1) << endl;

            cout << endl
                 << "-------4.2-------" << endl
                 << endl
                 << endl;
            cout << "All combinations that equal 33: " << sumTotal[33] << endl
                 << endl;
            cout << endl
                 << "-------4.3-------" << endl
                 << endl
                 << endl;
            for (int w = 0; w < 133; w++)
            {
                //cout << w << " " << sumTotal[w] << endl;
                cout << sumTotal[w] << " combinations of different elements sum to " << w << endl;
            }
            break;
        }
    }
    else
    {
        cout << endl
             << "-------4.1-------" << endl
             << endl
             << endl;
        cout << "Number of 4-element combinations that equal 33: " << comb4(0) << endl
             << endl;
        cout << "Proof: " << endl;
        cout << comb4(1) << endl;

        cout << endl
             << "-------4.2-------" << endl
             << endl
             << endl;
        cout << "All combinations that equal 33: " << sumTotal[33] << endl
             << endl;
        cout << endl
             << "-------4.3-------" << endl
             << endl
             << endl;
        for (int w = 0; w < 133; w++)
        {
            //cout << w << " " << sumTotal[w] << endl;
            cout << sumTotal[w] << " combinations of different elements sum to " << w << endl;
        }
    }
}