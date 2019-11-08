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
double current = 0;
double last = -1;

unsigned long int lucas(int n)
//need to check if >0 for inital n
{
    if (n == 0)
    {
        if (n == printed)
        {
            //this is for printing values
            cout << n << ": " << 2 << endl;
            cout << "time: " << (current = ((double)(clock() - t) / CLOCKS_PER_SEC)) << endl;
            cout << "ratio: " << (current / last) << endl;
            last = current;
            cout << endl;

            printed++;
        }
        return 2; //base case R(0)
    }
    else if (n == 1)
    {
        if (n == printed)
        {
            //this is for printing values
            cout << n << ": " << 1 << endl;
            cout << "time: " << (current = ((double)(clock() - t) / CLOCKS_PER_SEC)) << endl;
            cout << "ratio: " << (current / last) << endl;
            cout << endl;
            last = current;
            printed++;
        }
        return 1; //base case R(1)
    }
    else
    {
        long int r = lucas(n - 1) + lucas(n - 2); //recurse
        if (n == printed)
        {
            //this is for printing values
            cout << n << ": " << r << endl;
            cout << "time: " << (current = ((double)(clock() - t) / CLOCKS_PER_SEC)) << endl;
            cout << "ratio: " << (current / last) << endl;
            cout << endl;
            last = current;
            printed++;
        }

        return r; //step out
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "./p3 [number to run]" << endl; //useage
        exit(1);
    }
    int max = atoi(argv[1]); //max value from command line
    printed = 0;             //used in printing numbers
    t = clock();             //used in time calculation
    unsigned long int r = lucas(max);
    cout << max - 1 << ": " << r << endl;
    cout << "time: " << (current = ((double)(clock() - t) / CLOCKS_PER_SEC)) << endl;
    cout << "ratio: " << (current / last) << endl;
}