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
    // If the character is a digit then it must
    // be an operand
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

        // If the scanned character is an
        // operand, add it to output.
        if (isalpha(infix[i]) || isdigit(infix[i]))
            output += infix[i];

            // If the scanned character is an
            // ‘(‘, push it to the stack.
        else if (infix[i] == '(')
            conversionStack.push('(');

            // If the scanned character is an
            // ‘)’, pop and output from the stack
            // until an ‘(‘ is encountered.
        else if (infix[i] == ')') {
            while (conversionStack.getTop() != '(') {
                output += conversionStack.getTop();
                conversionStack.pop();
            }

            // Remove '(' from the stack
            conversionStack.pop();
        }

            // Operator found
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

                // Push current Operator on stack
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
    // Reverse String and replace ( with ) and vice versa
    // Get Postfix
    // Reverse Postfix
    int l = infix.size();

    // Reverse infix
    reverse(infix.begin(), infix.end());

    // Replace ( with ) and vice versa
    for (int i = 0; i < l; i++) {

        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    string prefix = infixToPostfix(infix);

    // Reverse postfix
    reverse(prefix.begin(), prefix.end());

    return prefix;
}

char Expression::evaluatePrefix(string exprsn)
{
    Stack myStack;

    for (int j = exprsn.size() - 1; j >= 0; j--) {

        // Push operand to Stack
        // To convert exprsn[j] to digit subtract
        // '0' from exprsn[j].
        if (isOperand(exprsn[j]))
            myStack.push(exprsn[j] - '0');

        else {

            if(exprsn[j] == '~')
            {
                int o1 = myStack.getTop();
                myStack.pop();
                myStack.push(char(int(~o1)));
                continue;
            }
            // Operator encountered
            // Pop two elements from Stack
            int o1 = myStack.getTop();
            myStack.pop();
            int o2 = myStack.getTop();
            myStack.pop();

            // Use switch case to operate on o1
            // and o2 and perform o1 Or o2.
            switch (exprsn[j]) {
                case '+':
                    myStack.push(char(o1 + o2));
                    break;
                case '-':
                    myStack.push(char(o1 - o2));
                    break;
                case '*':
                    myStack.push(char(o1 * o2));
                    break;
                case '/':
                    myStack.push(char(o1 / o2));
                    break;
                case '|':
                    myStack.push(char(o1 || o2));
                    break;
                case '&':
                    myStack.push(char(o1 & o2));
                    break;
                default:
                    break;
            }
        }
    }

    return myStack.getTop();
}