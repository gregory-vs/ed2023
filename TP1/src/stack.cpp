#include <iostream>
#include "../include/stack.h"
using namespace  std;



Stack::~Stack()
{
    while (!isEmpty())
    {
        pop();
    }
}

//pushes element on to the stack
bool Stack::push(char element)
{
    Node* newNode = new Node;
    newNode->value = element;
    newNode->next = top;
    top = newNode;
    cout<<"elemento" << element << "empilhado com sucesso" << endl;
}

//removes or pops elements out of the stack
char Stack::pop()
{
    if(!isEmpty())
    {
        char elementPopped = top->value;
        Node* temp = top;
        top = top->next;
        delete temp;
        cout << "elemento" << elementPopped << "desempilhado com sucesso" << endl;
        return elementPopped;
    }
    else
    {
        cerr<<"Erro: pilha vazia, impossivel desempilhar" << endl;
        return -1;
    }
}

//check if stack is empty
bool Stack::isEmpty() const
{
    return top == nullptr;
}

char Stack::getTop() const
{
    if(!isEmpty())
    {
        return top->value;
    }
    else
    {
        cerr << "Erro: Pilha vazia, não há topo para acessar" << endl;
        return -1;
    }
}

