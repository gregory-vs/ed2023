#include <iostream>
#include "../include/stack.h"

Stack::Stack()
{
    elements = new int[MAX];
    top = -1;
}

Stack::~Stack()
{
    delete[] elements;
}

//pushes element on to the stack
bool Stack::push(char item)
{
    if (top >= (MAX-1)) {
        cout << "Stack Overflow!!!";
        return false;
    }
    else {
        myStack[++top] = item;
        cout<<item<<endl;
        return true;
    }
}

//removes or pops elements out of the stack
char Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow!!";
        return 0;
    }
    else {
        int item = myStack[top--];
        return item;
    }
}

//check if stack is empty
bool Stack::isEmpty() const
{
    return (top < 0);
}

char Stack::getTop() const {
    return 0;
}

void Stack::setTop(char newTop) {

}

bool Stack::isFull() const {
    return false;
}

//char Stack::verifyTop()
//{
//    if(!isEmpty())
//        return elements[top];
//}
