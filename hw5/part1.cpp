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
    myfile.open("Raven.txt");
    vector<string> words;
    string temp;
    while (getline(myfile, temp, '\n'))
    {
        string buffer;
        stringstream ss(temp);
        while (ss >> buffer)
        {
            words.push_back(buffer);
        }
    }
    char symbols[] = {'"', '.', '-', ',', ';', ':', '!', '\n'};
    int l = strlen(symbols);
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
    cout << t.hash("he");
    /*
    for (int i = 0; i < words.size(); i++)
    {
        cout << i << " " << words[i] << " ";
        t.insert(words[i]);
    }
    t.printTable();
    */
}