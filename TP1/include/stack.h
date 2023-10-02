#ifndef STACK_H
#define STACK_H

class Stack
{
    private:
        struct Node{
            char value;
            Node* next;
        };

        Node* top; //pointer to the top of the stack

    public:
        Stack() : top(nullptr) {};
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
