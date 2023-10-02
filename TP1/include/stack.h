#ifndef STACK_H
#define STACK_H
#include "../include/node.h"

class Stack
{
    private:
        struct StackNode{
            Node* value;
            StackNode* next;
        };

        StackNode* top; //pointer to the top of the stack

    public:
        Stack() : top(nullptr) {};
        ~Stack();
        Node* getTop() const;
        bool isEmpty() const;
        void push(Node* x);
        void pop();
};


#endif //STACK_H
