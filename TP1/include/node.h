
#ifndef EXPRESSAO_H
#define EXPRESSAO_H
#include <iostream>
#include <string>

class Node {
    public:
        virtual bool evaluate() const =0;
        virtual  ~Node(){}
};

class NodeValue : public Node {
    private:
        bool value;

    public:
    NodeValue(bool val) : value(val) {};
    bool evaluate() const override;
};

class NodeOperator : public Node {
private:
    char oper;
    Node* left;
    Node* right;

public:
    NodeOperator(char op, Node* l, Node* r): oper(op), left(l), right(r) {}
    bool evaluate() const override;
    ~NodeOperator();
};


#endif //EXPRESSAO_H
