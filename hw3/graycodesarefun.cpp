#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

void printKids(int code)
{
    char *a = "", *b = "", *c = "", *d = "";
    if ((code >> 0) % 2 == 1)
    {
        a = "alice";
    }
    if ((code >> 1) % 2 == 1)
    {
        b = "bobby";
    }
    if ((code >> 2) % 2 == 1)
    {
        c = "chris";
    }
    if ((code >> 3) % 2 == 1)
    {
        d = "dylan";
    }
    printf("%6s%6s%6s%6s", a, b, c, d);
}

void BRGCProf(vector<string> v)
{
    for (int i = 1; i < v.size(); i++)
    {
        int a = stoi(v[i - 1], nullptr, 2);
        int b = stoi(v[i], nullptr, 2);
        int diff = a - b;

        printf("%2i", i);
        cout << " | " << v[i] << " |";
        printKids(b);
        cout << " | ";
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
    if (argc==2)
    {
        vector<string> r = BRGC(atoi(argv[1]));
        cout << r.size() << endl;
        for (int i = 0; i < r.size(); i++)
        {
            cout << r[i] << endl;
        }
    }
    
    vector<string> r = BRGC(4);
    cout << r.size() << endl;
    cout<<" i | code | name                    | action"<<endl;
    cout<<"--------------------------------------------"<<endl;
    BRGCProf(r);
}