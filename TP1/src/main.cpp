#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include "../include/stack.h"
#include "../include/node.h"

using namespace std;

bool evaluateExpression(const std::string& expression, const std::string& values){
    std::istringstream iss(expression);
    Stack stack;
    std::string token;

    while(iss >> token){
        if(token == "&" || token == "|" || token == "~" || token == "(")
        {
            char op = token[0];
            if(op == '(')
            {
                stack.push(new NodeOperator(op, nullptr, nullptr));
            }
            else if(op == '~')
            {
                char nextToken;
                iss >> nextToken;
                int var = nextToken - '0';
                stack.push(new NodeValue(values[var] == '1'));
            }
            else
            {
                Node* right = stack.getTop() == nullptr ? nullptr : stack.getTop();
                if(stack.getTop() != nullptr)
                    stack.pop();
                Node* left = stack.getTop() == nullptr ? nullptr : stack.getTop();
                if(stack.getTop() != nullptr)
                    stack.pop();
                stack.push(new NodeOperator(op, left, right));
            }
        }
        else if(isdigit(token[0]))
        {
            int var = std::stoi(token);
            stack.push(new NodeValue(values[var - '0'] == '1'));
        }
        else if(token == ")")
        {
            Node* subexpression = stack.getTop();
            stack.pop();
//            stack.getTop();
//            stack.pop();
            stack.push(subexpression);
        }

    }

    Node* result = stack.getTop();
    return result->evaluate();
}

int main(int argc,char *argv[])
{
    std::string expression = "0 | 1";
    std::string values = "01";

    bool root = evaluateExpression(expression, values);

    std::cout << "Resultado da expressao: " << int(root) << std::endl;

    return 0;

}