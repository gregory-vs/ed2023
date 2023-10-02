#ifndef STACK_H
#define STACK_H


#define MAX 1000 //max size for stack

class Stack
{
    private:
        int* element;
        char top;
        char myStack[MAX]; //stack array

    public:
        Stack();
        ~Stack();
        char getTop() const;
        void setTop(char newTop);
        bool isEmpty() const;
        bool isFull() const;
        bool push(char x);
        char pop();
        //char verifyTop();
};


#endif //STACK_H
