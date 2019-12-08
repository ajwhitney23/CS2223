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
void findMin(int i);
void dijkstra(int src, int dest);
void printSolution();
void findMin2();

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

    pathCost[0] = 0;        //pathCost from start will always be 0
    pathCostNodes[0] = src; //first node is src
    hasBeen[src] = 1;

    for (int j = 0; j < 9; j++)
    {
        int minCost = MAX_COST;
        int next;
        for (int i = 0; i < 10; i++)
        {
            if (pathCost[i] <= minCost && !hasBeen[i])
            {
                minCost = pathCost[i];
                next = i;
                if(next == dest)
                {
                    i = 10;
                }
            }
        }
        hasBeen[next] = 1;
        for(int i = 0; i < 10; i++)
        {
            if(hasBeen[dest])
            {
                break;
            }
            if(!hasBeen[i] && (minCost + aGraph[next][i] < pathCost[i])
                && aGraph[next][i])
            {
                pathCost[i] = minCost + aGraph[next][i];
                pathCostNodes[i] = next;
            }
        }
    }
    /*
    for(int i = 0; i < 10; i++)
    {
        if(i != src)
        {
            cout << "Distance of node " << i << " is " << pathCost[i] << endl;
            cout << "Path is " << i << endl;
            int j = i;
            do {
                j = pathCostNodes[j];
                cout << " <-- " << j;
            } while(j!=src);
            cout << endl;
        }
    }
    */
   printSolution();
}

//old function
void findMin(int temp)
{
    int min = MAX_COST;
    int tempNode;

    for (int i = 0; i < 10; i++) //go through each node
    {
        if (!hasBeen[i] && (pathCost[i] <= min)) //hasn't been and if pathCost at that spot is <= min
        {
            min = pathCost[i];
            tempNode = i;
        }
    }
    hasBeen[tempNode] = 1;
    pathCostNodes[temp] = tempNode;
    for (int k = 0; k < 10; k++)
    {
        cout << pathCost[tempNode] << endl;
        if (!hasBeen[k] && aGraph[tempNode][k] && (pathCost[tempNode] != MAX_COST) &&
            (pathCost[tempNode] + aGraph[tempNode][k] < pathCost[k]))
        //if hasn't been @ k and there is a value on graph and pathCost at tempNode isnt MAX_COST and
        {
            pathCost[k] = pathCost[tempNode] + aGraph[tempNode][k];
            pathCostNodes[temp] = tempNode;
        }
    }
}

void printSolution()
{
    for (int i = 0; i < 10; i++)
    {
        cout << pathCostNodes[i] << " ";
    }
    cout << endl;
    for (int j = 0; j < 10; j++)
    {
        cout << pathCost[j] << " ";
    }
    cout << endl;
}