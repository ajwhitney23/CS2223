#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

#define MAX_COST 999

int aGraph[10][10];    //grid read in from text
int pathCost[10];      //cost after i steps
int pathCostNodes[10]; //stores the path nodes
int hasBeen[10];       //checks if node has been visited

void initializeGraph();
void parseGraph();
void printArray();
void findMin();
void dijkstra(int src, int dest);
void printSolution();

int prevNodes[10];
int cost[10];

int main(int argc, char **argv)
{
    int src;
    int dest;
    cout << "Enter the source: " << endl;
    cin >> src;
    cout << "Enter the destination: " << endl;
    cin >> dest;
    initializeGraph();
    parseGraph();
    dijkstra(src, dest);
    return 0;
}

void initializeGraph()
{
    int i;
    int j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            aGraph[i][j] = 0;
        }
    }
}

void parseGraph()
{
    fstream file;          //create file stream
    file.open("grid.txt"); //open text file to be read
    int i;
    int j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            file >> aGraph[i][j]; //read file into the array
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
            cout << aGraph[i][j] << " ";
        }
        cout << endl;
    }
}

void dijkstra(int src, int dest)
{
    for (int i = 0; i < 10; i++)
    {
        pathCost[i] = MAX_COST;
        hasBeen[i] = 0;
    }

   pathCost[src] = 0;

    for (int j = 0; j < 9; j++)
    {
        findMin();
    }
   printSolution();
}

void findMin()
{
    int min = MAX_COST;
    int tempNode;

    for (int i = 0; i < 10; i++) //go through each node
    {
        if (!hasBeen[i] && (pathCost[i] <= min)) //hasn't been and if pathCost at that spot is <= min
        {
            //cout << "entered if due to "<< i << endl;
            min = pathCost[i];
            tempNode = i;
        }
    }
    hasBeen[tempNode] = 1;
    pathCostNodes[tempNode] = tempNode;
    int temp;
    for (int k = 0; k < 10; k++)
    {
        if (!hasBeen[k] && aGraph[tempNode][k] && (pathCost[tempNode] != MAX_COST) &&
            (pathCost[tempNode] + aGraph[tempNode][k] < pathCost[k]))
        //if hasn't been @ k and there is a value on graph and pathCost at tempNode isnt MAX_COST and
        {
            temp = k;
            pathCost[k] = pathCost[tempNode] + aGraph[tempNode][k];
            pathCostNodes[tempNode] = tempNode;
        }
    }
    //cout << "node being stored " << tempNode << endl;
    //cout << "value " << pathCost[temp] << endl;
}

void printSolution()
{
    cout << endl << endl;
    cout << "Order: ";
    for (int i = 0; i < 10; i++)
    {
        cout << pathCostNodes[i] << " ";
    }
    cout << endl;
    cout << "Values: ";
    for (int j = 0; j < 10; j++)
    {
        cout << pathCost[j] << " ";
    }
    cout << endl;
}