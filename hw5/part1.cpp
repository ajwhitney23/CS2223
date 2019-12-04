#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

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
            words.at(i).erase(remove(words.at(i).begin(), words.at(i).end(), symbols[j]), words.at(i).end());
        }
        if (words.at(i).empty())
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
    for (int i = 0; i < words.size(); i++)
    {
        cout << words.at(i) << endl;
    }
    cout << words.size() << endl;
}