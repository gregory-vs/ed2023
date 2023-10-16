#ifndef STACK_H
#define STACK_H
#include<iostream>

struct node
{
    char data;
    node *next;
};


class Stack
{
    node *top;

    public:
        Stack() {top = NULL;}
        ~Stack();
        char getTop() const;
        bool isEmpty() const;
        void push(char c);
        void pop();
};


#endif //STACK_H
