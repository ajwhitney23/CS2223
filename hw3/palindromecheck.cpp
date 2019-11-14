#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string stripInput(string input)
{
    string punc = "! .,;:";
    for_each(input.begin(), input.end(), [](char &c) {
        c = tolower(c);
    });
    for (char x : punc)
    {
        input.erase(remove(input.begin(), input.end(), x), input.end());
    }

    //cout << input << endl; //debug
    return input;
}

int isPalindrome(string input)
{
    int i = 0;
    string aString = stripInput(input);
    for (i = 0; i < aString.length() - 1; i++)
        ;
    {
        if (aString.at(i) != aString.at(aString.length() - i - 1))
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        string input = argv[1];
        if (isPalindrome(input))
        {
            cout << "It is a palindrome" << endl;
        }
        else
        {
            cout << "It is not a palindrome" << endl;
        }
    }
    else
    {
        cout << "Usage: ./palindrome \"Potential Palindrome\"" << endl;
        cout << "Input must be within two \"s in order to work as intended" << endl;
    }

    return 0;
}