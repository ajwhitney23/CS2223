#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

int aGrid[10][10];    //grid read in from text
//int outputNode[10];
int output[10];       //output array
int shortestPath[10]; //name of vertext of shortest path

void initializeGrid();
void parseGrid();
void printArray();
void findMin();
void dijkstra(int src, int dest);
void printSolution(); 


int main(int argc, char **argv)
{
    int src;
    int dest;
    cout << "Enter the source: " << endl;
    cin >> src;
    cout << "Enter the destination: " << endl;
    cin >> dest;
    initializeGrid();
    parseGrid();
    dijkstra(src, dest);
    return 0;
}

void initializeGrid()
{
    int i;
    int j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            aGrid[i][j] = 0;
        }
    }
}

void parseGrid()
{
    fstream file;          //create file stream
    file.open("grid.txt"); //open text file to be read
    int i;
    int j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            file >> aGrid[i][j]; //read file into the array
        }
    }
    file.close(); //close now that we are done
    printArray();
}

void printArray()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << aGrid[i][j] << " ";
        }
        cout << endl;
    }
}

void dijkstra(int src, int dest)
{
    for (int i = 0; i < 10; i++)
    {
        output[i] = 999;
        shortestPath[i] = 0;
    }
    output[src] = 0;
    // outputNode[src] = src;

    for(int j = 0; j < 9; j++)
    {
        findMin();
    }
    printSolution();
}

void findMin()
{
    int min = 999;
    int tempNode;

    for (int i = 0; i < 10; i++)
    {
        if (shortestPath[i] == 0 && output[i] <= min)
        {
            min = output[i];
            tempNode = i;
        }
    }
    shortestPath[tempNode] = 1;
    for (int k = 0; k < 10; k++)
    {
        if (!shortestPath[k] && aGrid[tempNode][k] && output[tempNode] != 999 && 
            output[tempNode] + aGrid[tempNode][k] < output[k])
        {
            output[k] = output[tempNode] + aGrid[tempNode][k];
            // outputNode[k] = tempNode;
        }  
    }
}

void printSolution() 
{ 
    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < 10; i++)
    {
        printf("%d \t\t %d\n", i, output[i]);
    }  
}