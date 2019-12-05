#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

const int C = 123;

class HashTable
{
private:
    string *table;
    int size;

public:
    HashTable()
    {
        HashTable(1);
    }
    HashTable(int size)
    {
        table = new string[size];
        this->size = size;
    }
    int hash(string s);
    int insert(string v);
    string getKey(int k);
    void printTable();

    ~HashTable()
    {
    }
};

int HashTable::hash(string s)
{
    int ret = 0;
    for (int i = 0; i < s.length(); i++)
    {
        ret += (ret * C + (int)s[i]) % size;
    }
    return (ret % (size - 1));
}

//insert string into table, returns 1 if insert is successful, 0 if failed insert
int HashTable::insert(string v)
{
    int h = hash(v);
    cout << "insert " << h << ": ";
    if (table[h].empty())
    {
        cout << "easy insert" << endl;
        table[h] = v; //insert to empty spot
        return 1;
    }
    else if (table[h] == v)
    {
        cout << "duplicate " << v << endl;
        return 1; //check if we're gonna insert duplicate, then avoid
    }
    else
    {
        //hash collision, so we do closed addressing
        //iterate circularly around table
        int start = h;           //start point to end while loop
        int i = h + 1;           //next item
        bool insertFlag = false; //did we insert successfully?
        while (start != i)
        {
            if (table[i].empty())
            {
                cout << "insert via while at " << i << endl;
                table[i] = v;      //insert to open spot
                insertFlag = true; //set flag
                break;
            }
            i++; //iterate
            if (i == size)
            {
                i = 0; //wrap around to beginning
            }
        }
        if (!insertFlag)
        {
            return 0; //failed insert
        }
    }
    return 1;
}

string HashTable::getKey(int k)
{
    if (k >= size)
    {
        return NULL;
    }
    return table[k];
}

void HashTable::printTable()
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(3) << i << " | " << setw(25) << table[i] << " | " << setw(10) << hash(table[i]) << endl;
    }
}