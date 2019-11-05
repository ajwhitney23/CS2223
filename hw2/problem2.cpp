/*
 * TODO: 
 * MAKEFILE
 * write main to ask for input
 * call recursive function
 */
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
int printed;

long int p2(int n)
//need to check if >0 for inital n
{
    if (n == 0)
    {
        if (n == printed)
        {
            cout << n << ": " << 2 << endl;
            printed++;
        }
        return 2;
    }
    else if (n == 1)
    {
        if (n == printed)
        {
            cout << n << ": " << 1 << endl;
            printed++;
        }
        return 1;
    }
    else
    {
        long int r = p2(n - 1) + p2(n - 2);
        if (n == printed)
        {
            cout << n << ": " << r << endl;
            printed++;
        }

        return r;
    }
}

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        cout << "./p2 [number to run]" << endl;
        exit(1);
    }
    int max = atoi(argv[1]);
    printed = 0;
    int r = p2(max);
    cout << max << ": " << r << endl;
    /*
    for (int i = 0; i < max; i++)
    {
        cout << i << ": " << p2(i) << endl;
    }
    */
}