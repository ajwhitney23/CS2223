#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string stripInput(string input)
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
    return input;
}

int isPalindrome(string input)
{ 
    int i = 0;
    string aString = stripInput(input);
    for(i = 0; i < aString.length() - 1; i++);
    {
        if(aString.at(i) != aString.at(aString.length() - i - 1)){
            return 0;
        }
        else{
            return 1;
        }
    }
    /*
    check if beginning and end are equal
    check if beginning + 1 and end - 1 are equal... contintue until done
    */
}




int main(int agrc, char **argv)
{
    string input = argv[1];
    if(isPalindrome(input))
    {
        cout << "It is a palindrome" << endl;
    }
    else 
    {
        cout << "It is not a palindrome" << endl;
    }
    
    return 0;
}