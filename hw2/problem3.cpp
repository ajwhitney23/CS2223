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
clock_t t;

long int p2(int n)
//need to check if >0 for inital n
{
    if (n == 0)
    {
        if (n == printed)
        {
            cout << n << ": " << 2 << endl;
            cout << "time: " << ((double)(clock() - t)/CLOCKS_PER_SEC) << endl;
            cout << endl;
            printed++;
        }
        return 2;
    }
    else if (n == 1)
    {
        if (n == printed)
        {
            cout << n << ": " << 1 << endl;
            cout << "time: " << ((double)(clock() - t)/CLOCKS_PER_SEC) << endl;
            cout << endl;
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
            cout << "time: " << ((double)(clock() - t)/CLOCKS_PER_SEC) << endl;
            cout << endl;
            printed++;
        }

        return r;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "./p3 [number to run]" << endl;
        exit(1);
    }
    int max = atoi(argv[1]);
    printed = 0;
    t = clock();
    int r = p2(max);
    cout << max - 1 << ": " << r << endl;
    cout << "time: " << ((double)(clock() - t)/CLOCKS_PER_SEC) << endl;
    /*
    for (int i = 0; i < max; i++)
    {
        cout << i << ": " << p2(i) << endl;
    }
    */
}