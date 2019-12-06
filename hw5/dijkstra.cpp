#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

int aGrid[10][10];

int shortestPath[10]; //used to store overall current shortest path
int path[10]; //used to store path

void parseGrid();
void printArray();

int main(int argc, char** argv)
{
    int i;
    int j;
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            aGrid[i][j] = 0;
        }
    }
    parseGrid();



    return 0;
}

void parseGrid()
{
    fstream file;
    file.open("grid.txt");
    char array[10];
    int i = 0;
    while(getline(file, array))
    {

        i++;
    }
    printArray();

}


void printArray()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << aGrid[i][j] << ", ";
        }
        cout << endl;
    }
}
