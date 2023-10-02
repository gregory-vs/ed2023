#include <iostream>
#include <string>
#include <sstream>
#include "../include/stack.h"
#include "../include/node.h"

using namespace std;

bool evaluateExpression(const std::string& expression, const std::string& values){
    std::istringstream iss(expression);
    Stack stack;
    Node* result = nullptr;

    int var;
    char op;
    while(iss >> var){
        char nextChar;
        iss >> nextChar;
        if(nextChar == '&')
            op = '&';
        else if(nextChar == '|')
            op = '|';
        else if(nextChar == '~')
            op = '~';
        else if(nextChar == '('){
            stack.push(new NodeValue(values[var - '0'] == '1'));
            continue;
        }
        else if(nextChar == ')')
        {
            Node* right = stack.getTop();
            stack.pop();
            Node* left = stack.getTop();
            stack.pop();
            if(op == '&')
                result = new NodeOperator('&', left, right);
            else if(op == '|')
                result = new NodeOperator('|', left, right);

            stack.push(result);
            continue;
        }

        if(op == '~'){
            Node* operand = stack
        }
    }
}

int main(int argc,char *argv[])
{
    std::string expression = "(1 & ~0) | (1 & 1)";

    int index = 0;
    Node* root = buildExpression(expression, index);
    if (root) {
        std::cout << "Resultado da expressao: " << root->evaluate() << std::endl;
        delete root;
    }

    return 0;

}