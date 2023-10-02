#include <iostream>
#include "../include/stack.h"
#include "../include/node.h"

bool NodeValue::evaluate() const
{
    return value;
}

bool NodeOperator::evaluate() const
{
    if (oper == '&')
        return left->evaluate() && right->evaluate();
    else if (oper == '|')
        return left->evaluate() || right->evaluate();
    else if (oper == '~')
        return !left->evaluate();
    else
    {
        std::cerr << "Operador invalido" << oper << std::endl;
        return false;
    }

    //todo mudar para case
}

NodeOperator::~NodeOperator()
{
    delete left;
    delete right;
}



