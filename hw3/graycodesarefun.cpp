#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

void decToBinary(int n)
{
    // array to store binary number
    int binaryNum[32];

    // counter for binary array
    int i = 0;
    while (n > 0)
    {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}

void printBin(int n)
{
    int binary[32];

    for (int i = 0; i < 32 && n > 0; i++)
    {
        binary[i] = n % 2;
        n = n / 2;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        cout << binary[i];
    }
}

vector<string> BRGC(int n)
{
    vector<string> a;
    a.push_back("0");
    a.push_back("1");

    for (int i = 2; i < (1 << n); i = i << 1)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            a.push_back(a[j]);
        }
        for (int j = 0; j < i; j++)
        {
            a[j] = "0" + a[j];         //add 0's
            a[j + i] = "1" + a[j + i]; //add 1's
        }
    }
    return a;
}

//main function
int main(int argc, char **argv)
{
    vector<string> r = BRGC(atoi(argv[1]));
    cout << r.size() << endl;
    /*for (int i = 0; i < r.size(); i++)
    {
        cout << r[i] << endl;
    }
    */
}