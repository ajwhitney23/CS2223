/*
 * TODO: 
 * MAKEFILE
 * write main to ask for input
 * call recursive function
 */
#include <iostream>
#include <cstdlib>

using namespace std;
int printed;

long int p2(int n)
//need to check if >0 for inital n
{
    if (n == 0)
    {
        if (n == printed)
        {
            //this is for printing values
            cout << n << ": " << 2 << endl;
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
            printed++;
        }
        return 1; //base case R(1)
    }
    else
    {
        long int r = p2(n - 1) + p2(n - 2); //recurse
        if (n == printed)
        {
            //this is for printing values
            cout << n << ": " << r << endl; //print result at this level
            printed++;
        }

        return r; //step out
    }
}

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        cout << "./p2 [number to run]" << endl; //useage
        exit(1);
    }
    int max = atoi(argv[1]); //max value from command line
    printed = 0;             //used in printing numbers
    int r = p2(max);
    cout << max << ": " << r << endl; //print last
}