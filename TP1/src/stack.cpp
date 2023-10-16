#include <iostream>
#include "../include/stack.h"

Stack::~Stack()
{
    while (top != NULL)
    {
        node *temp = top;
        top = top->next;
        delete temp;
    }
}

//pushes element on to the stack
void Stack::push(char c)
{
    node *temp;
    temp = new node;
    temp->data = c;
    temp->next = top;
    top = temp;
}

//removes or pops elements out of the stack
void Stack::pop()
{
    if(top != NULL)
    {
        node *temp = top;
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
    return top == NULL;
}

char Stack::getTop()  const
{
    if(!isEmpty())
        return top->data;

    return false;
}

