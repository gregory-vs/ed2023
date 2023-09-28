#ifndef STACK_H
#define STACK_H


#define MAX 1000 //max size for stack

class Stack
{
    private:
        int* element;
        int top;
        int myStack[MAX]; //stack array

    public:
        Stack();
        ~Stack();
        bool push(int x);
        int pop();
        bool isEmpty();
        int verifyTop();
};


#endif //STACK_H
