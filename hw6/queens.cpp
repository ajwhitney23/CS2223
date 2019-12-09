#include <cstdlib>
#include <iostream>
using namespace std;

#define BOARD_SIZE 4

int isTrue[BOARD_SIZE] = {3, 1, 4, 2};
int isFalse[BOARD_SIZE] = {1, 2, 3, 4};

bool isLegalPosition(int array[], int n)
{
    return true;
}




int main(int argc, char** argv)
{
    int x = isLegalPosition(isTrue, BOARD_SIZE);
    if(x)
    {
        cout << "it is a legal position" << endl;
    }
    if(!x)
    {
        cout << "it is not a legal position" << endl;
    }
    return 0;
}