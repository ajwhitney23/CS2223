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
    void printTable();

    void part3a();
    void part3b();
    void part3c();
    void part3d();
    void part3e();

    ~HashTable()
    {
    }
};

int HashTable::hash(string s)
{
    int ret = 0;
    for (int i = 0; i < s.length(); i++)
    {
        //i tried my best to implement off the PDF but i'm still not 100% i got it right
        ret += (ret * C + (int)s[i]) % (size - 1);
    }
    return (ret % (size - 1));
}

//insert string into table, returns 1 if insert is successful, 0 if failed insert
int HashTable::insert(string v)
{
    if (v.empty())
    {
        return 0; //don't insert empty strings
    }
    int h = hash(v);
    //cout << "insert " << h << ": ";
    if (table[h].empty())
    {
        //cout << "easy insert" << endl;
        table[h] = v; //insert to empty spot
        return 1;
    }
    else if (table[h] == v)
    {
        //cout << "duplicate " << v << endl;
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
                //cout << "insert via while at " << i << endl;
                table[i] = v;      //insert to open spot
                insertFlag = true; //set flag
                break;
            }
            else if (table[i] == v)
            {
                //cout << "duplicate via while at " << i << endl;
                return 1;
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

void HashTable::printTable()
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(3) << i << " | " << setw(25) << table[i] << " | " << setw(10) << hash(table[i]) << endl;
    }
}

void HashTable::part3a()
{
    int nonEmpty = 0; //stores the number of non-empty elements
    for (int i = 0; i < size; i++)
    {
        if (!table[i].empty())
        {
            nonEmpty++; //count the number of non-empty elements
        }
    }

    cout << "Part 3a: " << nonEmpty << endl;
    cout << "Load Factor: " << ((1.0 * nonEmpty) / size) << endl; //multiply by 1.0 to promote to float
}

void HashTable::part3b()
{
    int bestStart = 0;           //best region start location
    int bestSize = 0;            //best region size
    int emptyStart = 0;          //current region start location
    int emptySize = 0;           //current region size
    bool regionContinue = false; //used to know if we've started another empty region
    bool isEmpty;                //is current location empty?
    for (int i = 0; i < size; i++)
    {
        isEmpty = table[i].empty();
        if (isEmpty)
        {
            //current item is empty
            if (regionContinue)
            {
                emptySize++; //continuing the empty region
            }
            else
            {
                emptyStart = i;        //start new region here
                emptySize = 1;         //size is 1 to start
                regionContinue = true; //region will continue in next iteration
            }
        }
        else
        {
            //current item is not empty
            if (bestSize < emptySize)
            {
                //the region we just finished is our best region so far
                //overwrite our "best" variables
                bestStart = emptyStart;
                bestSize = emptySize;
            }
            regionContinue = false; //region counting will resume at
        }
    }
    cout << "Part 3b:\nThe largest region of empty space starts at " << bestStart << " and is " << bestSize << " long." << endl;
}

void HashTable::part3c()
{
    int bigStart = 0;             //largest cluster start location
    int bigSize = 0;              //largest cluster size
    int currentStart = 0;         //current cluster start location
    int currentSize = 0;          //current cluster size
    bool clusterContinue = false; //used to know if we've started another cluster region
    bool isClustered;             //is current location part of a cluster?
    for (int i = 0; i < size; i++)
    {
        isClustered = ((hash(table[i]) != i) && !table[i].empty());

        if (isClustered)
        {
            //current item isn't in right place, in cluster
            if (clusterContinue)
            {
                currentSize++; //continuing the empty region
            }
            else
            {
                currentStart = i;       //start new region here
                currentSize = 1;        //size is 1 to start
                clusterContinue = true; //region will continue in next iteration
            }
        }
        else
        {
            //current item is not empty
            if (bigSize < currentSize)
            {
                //the region we just finished is our best region so far
                //overwrite our "best" variables
                bigStart = currentStart;
                bigSize = currentSize;
            }
            clusterContinue = false; //region counting will resume at
        }
    }
    cout << "Part 3c:\nThe largest cluster starts at " << bigStart << " and is " << bigSize << " long." << endl;
}

void HashTable::part3d()
{
    int hashCount[size]; //value is the counter, and the index is the hash
    for (int i = 0; i < size; i++)
    {
        hashCount[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        if (!table[i].empty())
        {
            hashCount[hash(table[i])]++; //increment at the index, where the index is the hashed value of the word we're on
        }
    }
    int most = 0; //store hash with most distinct words
    for (int i = 0; i < size; i++)
    {
        if (hashCount[i] > most)
        {
            most = i; //set maximum
        }
    }
    cout << "Part 3d:\nHash with most distinct words is " << most << " with " << hashCount[most] << " hashes." << endl;
}

void HashTable::part3e()
{

    int bestDiff = 0;         //best difference
    int diff = 0;             //current difference
    string bestWord = "";     //best word
    string word = "";         //current word
    int bestPos = 0;          //best position
    bool isSeparated = false; //is the hash of the word not equal to its position?
    int currentHash = 0;      //hash of current item we're on (avoids repeated function calls)
    for (int i = 0; i < size; i++)
    {
        if (!table[i].empty())
        {
            //set current hash and check if element is separated
            currentHash = hash(table[i]);
            isSeparated = (currentHash != i);
            if (isSeparated)
            {
                diff = i - currentHash; //the difference between the index of the word and what the index should be
                if (diff > bestDiff)
                {
                    bestWord = table[i]; //set the best word
                    bestDiff = diff;     //set the best difference
                    bestPos = i;         //set the best position (purely to print it)
                }
            }
        }
    }
    cout << "Part3e:\nThe word farthest from actual hash is \"" << bestWord << "\" with a difference of " << bestDiff << " away from " << bestPos << "." << endl;
}