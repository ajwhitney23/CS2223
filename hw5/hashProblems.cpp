#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include "hash.cpp"

using namespace std;

vector<string> readRaven()
{
    fstream myfile;
    myfile.open("Raven.txt", ios::in);
    vector<string> words;
    string temp;
    while (myfile >> temp)
    {
        words.push_back(temp);
    }
    myfile.close();

    //removes undesireable symbols
    char symbols[] = {'\"', '.', '-', ',', ';', ':', '!', '?'};
    int l = 8;
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < l; j++)
        {
            words[i].erase(remove(words[i].begin(), words[i].end(), symbols[j]), words[i].end());
        }
        if (words[i].empty())
        {
            words.erase(words.begin() + i);
            i--;
        }
    }
    return words;
}

int main()
{
    vector<string> words = readRaven();
    HashTable t = HashTable(1000);
    for (int i = 0; i < words.size(); i++)
    {
        //cout << i << " " << words[i] << " ";
        t.insert(words[i]);
    }
    t.printTable();
    t.part3a();
    t.part3b();
    t.part3c();
    t.part3d();
    t.part3e();
}