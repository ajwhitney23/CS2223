#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char reverse[256];


void stripInput(string input)
{
    string punc = "! .,;:";
    for_each(input.begin(), input.end(), [](char & c)
    {
        c = tolower(c);
    });
    for(char x: punc) {
        input.erase(remove(input.begin(), input.end(), x), input.end());
    }

    cout << input << endl;
}

int isPalindrome(string input)
{
    stripInput(input);
    /*
    check if beginning and end are equal
    check if beginning + 1 and end - 1 are equal... contintue until done
    */
}




int main(int agrc, char **argv)
{
    //string input = argv[1];
    if(isPalindrome(argv[1]))
    {
        cout << "It is a palindrome" << endl;
    }
    else 
    {
        cout << "It is not a palindrome" << endl;
    }
    
    return 0;
}