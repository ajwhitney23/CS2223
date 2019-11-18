#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

void BRGCProf(vector<string> v)
{
    for (int i = 1; i < v.size(); i++)
    {
        int a = stoi(v[i - 1], nullptr, 2);
        int b = stoi(v[i], nullptr, 2);
        int diff = a - b;
        cout << v[i] << ": ";
        if (abs(diff) == 1)
        {
            cout << "alice";
        }
        else if (abs(diff) == 2)
        {
            cout << "bob";
        }
        else if (abs(diff) == 4)
        {
            cout << "chris";
        }
        else if (abs(diff) == 8)
        {
            cout << "dylan";
        }
        if (diff < 0)
        {
            cout << " in" << endl;
        }
        else
        {
            cout << " out" << endl;
        }
    }
}

vector<string> BRGC(int n)
{
    vector<string> v;
    v.push_back("0");
    v.push_back("1");

    for (int i = 2; i < (1 << n); i = i << 1)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            v.push_back(v[j]);
        }
        for (int j = 0; j < i; j++)
        {
            v[j] = "0" + v[j];         //add 0's
            v[j + i] = "1" + v[j + i]; //add 1's
        }
    }
    return v;
}

//main function
int main(int argc, char **argv)
{
    vector<string> r = BRGC(atoi(argv[1]));
    cout << r.size() << endl;
    /*for (int i = 0; i < r.size(); i++)
    {
        cout << r[i] << endl;
    }*/
    BRGCProf(r);
}