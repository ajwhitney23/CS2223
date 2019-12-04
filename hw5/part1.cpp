#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main()
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
    for (int i = 0; i < words.size(); i++)
    {
        cout << words.at(i) << endl;
    }
}