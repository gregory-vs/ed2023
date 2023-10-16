#include <iostream>
#include <string>
#include <cctype>
#include "../include/expression.h"

using namespace std;

string removeWhiteSpaces(const string& input)
{
    string result;
    for (char caractere : input) {
        if (caractere != ' ') {
            result += caractere;
        }
    }
    return result;
}

string replaceValoration(const string& input, const string& value)
{
    string myString = input;
    int size = input.size();
    int j = 0;
    for (int i = 0; i < size; ++i) {
        if (isdigit(input[i])) {
            myString[i] = value[j];
            j++;
        }
    }
    return myString;
}

int main(int argc,char *argv[])
{
    string s = "0 | 1 & 2";
    string p = "010";
    char result;
    s = removeWhiteSpaces(s);
    p = removeWhiteSpaces(p);
    s = replaceValoration(s, p);
    s = Expression::infixToPrefix(s);
    result = Expression::evaluatePrefix(s);

    cout << int(result);

    return 0;

}