#include <iostream>
#include <string>
#include <cctype>
#include <bits/stdc++.h>
#include "../include/expression.h"
#include "../include/stack.h"

using namespace std;

bool Expression::isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}

bool isOperand(char c)
{
    return isdigit(c);
}

int Expression::getPriority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}

string Expression::infixToPostfix(string infix)
{
    infix = '(' + infix + ')';
    int l = infix.size();
    Stack conversionStack;
    string output;

    for (int i = 0; i < l; i++) {

        if (isalpha(infix[i]) || isdigit(infix[i]))
            output += infix[i];

        else if (infix[i] == '(')
            conversionStack.push('(');

        else if (infix[i] == ')') {
            while (conversionStack.getTop() != '(') {
                output += conversionStack.getTop();
                conversionStack.pop();
            }

            conversionStack.pop();
        }

        else {
            if (isOperator(conversionStack.getTop())) {
                if (infix[i] == '^') {
                    while (
                            getPriority(infix[i])
                            <= getPriority(conversionStack.getTop())) {
                        output += conversionStack.getTop();
                        conversionStack.pop();
                    }
                }
                else {
                    while (
                            getPriority(infix[i])
                            < getPriority(conversionStack.getTop())) {
                        output += conversionStack.getTop();
                        conversionStack.pop();
                    }
                }

                conversionStack.push(infix[i]);
            }
        }
    }
    while (!conversionStack.isEmpty()) {
        output += conversionStack.getTop();
        conversionStack.pop();
    }
    return output;
}

string Expression::infixToPrefix(string infix)
{
    int l = infix.size();

    reverse(infix.begin(), infix.end());

    for (int i = 0; i < l; i++) {

        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    string prefix = infixToPostfix(infix);

    reverse(prefix.begin(), prefix.end());

    return prefix;
}

char Expression::evaluatePrefix(string exprsn)
{
    Stack myStack;

    for (int j = exprsn.size() - 1; j >= 0; j--) {

        if (isOperand(exprsn[j]))
            myStack.push(to_string(exprsn[j] - '0')[0]);
        else {
            if(exprsn[j] == '~')
            {
                int o1 = stoi(string(1,myStack.getTop()));
                myStack.pop();
                myStack.push(to_string(~o1)[0]);
                continue;
            }

            int o1 = stoi(string(1,myStack.getTop()));
            myStack.pop();
            int o2 = stoi(string(1,myStack.getTop()));
            myStack.pop();

            switch (exprsn[j]) {
                case '+':
                    myStack.push(to_string(o1 + o2)[0]);
                    break;
                case '-':
                    myStack.push(to_string(o1 - o2)[0]);
                    break;
                case '*':
                    myStack.push(to_string(o1 * o2)[0]);
                    break;
                case '/':
                    myStack.push(to_string(o1 / o2)[0]);
                    break;
                case '|':
                    myStack.push(to_string(o1 || o2)[0]);
                    break;
                case '&':
                    myStack.push(to_string(o1 & o2)[0]);
                    break;
                default:
                    break;
            }
        }
    }

    return myStack.getTop();
}