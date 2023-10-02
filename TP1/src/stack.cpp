#include <iostream>
#include "../include/stack.h"
#include "../include/node.h"

Stack::~Stack()
{
    while (!isEmpty())
    {
        pop();
    }
}

//pushes element on to the stack
void Stack::push(Node* element)
{
    StackNode* newNode = new StackNode;
    newNode->value = element;
    newNode->next = top;
    top = newNode;
}

//removes or pops elements out of the stack
void Stack::pop()
{
    if(!isEmpty())
    {
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }
    else
    {
        std::cerr<<"Erro: pilha vazia, impossivel desempilhar" << std::endl;
    }
}

//check if stack is empty
bool Stack::isEmpty() const
{
    return top == nullptr;
}

Node* Stack::getTop()  const
{
    if(!isEmpty())
    {
        return top->value;
    }
    else
    {
        std::cerr << "Erro: Pilha vazia, não há topo para acessar" << std::endl;
        return nullptr;
    }
}

