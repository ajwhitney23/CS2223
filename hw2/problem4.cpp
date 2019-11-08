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
int sumTotal[133];  //{0, 4, 1} would mean the sum was 0 0 times, 1 4 times, and 2 1 time...
int nComTotal[133]; // {0, 4, 1} would mean there are 0 n-element combinations that equal 0, 4 that equal 1, 1 that equal 2

int comb4(int printFlag)
{
    int acc = 0; //accumulator
    //first loop
    for (int i = 0; i < 13; i++)
    {
        //second loop
        for (int j = i + 1; j < 14; j++)
        {
            //third loop
            for (int k = j + 1; k < 15; k++)
            {
                //fourth loop
                for (int l = k + 1; l < 16; l++)
                {
                    if ((list[i] + list[j] + list[k] + list[l]) == 33)
                    {
                        //when the sum of all 4 elements is 33
                        if (printFlag)
                        {
                            //used in printing proof
                            printf("index: i, %2i | j, %2i | k, %2i | l,%2i \n", i, j, k, l); //prints index in list[]
                            printf("value: i, %2i | j, %2i | k, %2i | l,%2i \t(%2i)\n\n", list[i], list[j], list[k], list[l],
                                   (list[i] + list[j] + list[k] + list[l])); //prints value at index
                        }
                        acc++; //accumulate
                    }
                }
            }
        }
    }
    return acc; //return accumulation
}

void combN(int maxDepth, int cDepth, int indexPrev, int sumPrev)
{
    if (maxDepth == cDepth)
    {
        //if at max "loop" depth (similar to comb4 where this is the final loop)
        for (int i = indexPrev; i < 16; i++)
        {
            int sum = sumPrev + list[i];
            sumTotal[sum]++; //increment the array given the sum of all values up to this point
        }
    }
    else
    {
        for (int i = indexPrev; i < (16 - (maxDepth - (cDepth + 1))); i++)
        {
            combN(maxDepth, 1 + cDepth, i + 1, (sumPrev + list[i])); //go deeper
        }
    }
}

void do1()
{
    cout << endl
         << "-------4.1-------" << endl
         << endl
         << endl;
    cout << "Number of 4-element combinations that equal 33: " << comb4(0) << endl
         << endl;
    cout << "Proof: " << endl;
    cout << comb4(1) << endl;
}

void do2()
{
    cout << endl
         << "-------4.2-------" << endl
         << endl
         << endl;
    cout << "All combinations that equal 33: " << sumTotal[33] << endl
         << endl;
}

void do3()
{
    cout << endl
         << "-------4.3-------" << endl
         << endl
         << endl;
    for (int w = 0; w < 133; w++)
    {
        cout << sumTotal[w] << " combinations of different elements that sum to " << w << endl;
    }
}

void doAll()
{
    do1();
    do2();
    do3();
}

int main(int argc, char *argv[])
{
    int i = 0;
    for (i = 0; i < 133; i++)
    {
        sumTotal[i] = 0; //initialize array
    }
    sumTotal[0]++;

    for (i = 0; i < 16; i++)
    {
        combN(i, 0, 0, 0); //process array with different max "loop" depths
    }

    if (argc > 1)
    {
        //only print based on what question is desired to be answered
        switch ((atoi(argv[1])))
        {
        case 1:
            do1(); //print out solution to 4.1
            break;

        case 2:
            do2(); //print out solution to 4.2
            break;

        case 3:
            do3(); //print out solution to 4.3
            break;

        default:
            doAll(); //print out solution to all 3 questions
            break;
        }
    }
    else
    {
        doAll(); //print out solution to all 3 questions
    }
}