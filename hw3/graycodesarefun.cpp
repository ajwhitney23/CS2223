#include <cstdlib>
#include <iostream>
using namespace std;

void printBin(int n)
{
    int binary[32];

    for (int i = 0; i < 32 && n > 0; i++, n = n / 2)
    {
        binary[i] = n % 2;
    }

    for (int i = n - 1; i >= 0; i--)
        cout << binary[i];
}

int *BRGC(int n)
{
    if (n == 1)
    {
        int *ret = (int *)malloc((int)2);
        ret[0] = 0;
        ret[1] = 1;
        return ret;
    }
    else
    {
        int *BR = (int *)BRGC(n - 1);            //next lowest order codes
        int *L = (int *)malloc((int)(1 << (n))); //array to return
        for (int i = 0; i < (1 << (n - 1)); i++)
        {
            L[i] = BR[i];
            L[(1 << n) - i] = BR[i];
            L[(1 << n) - i] += (1 << n) ^ (1 << (n - 1)); //set end bit to 1, xor out the shifted bits that're set
        }
        free(BR);
        return L;
    }
}

//main function
int main(int argc, char **argv)
{
    int *r = BRGC(4);
    for (int i = 0; i < 16; i++)
    {
        printBin(r[i]);
    }
}