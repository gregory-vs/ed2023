#ifndef ED2023_EXPRESSION_H
#define ED2023_EXPRESSION_H

class Expression{
    public:
        static bool isOperator(char c);
        static int getPriority(char C);
        static std::string infixToPostfix(std::string infix);
        static std::string infixToPrefix(std::string infix);
        static char evaluatePrefix(std::string exprsn);
};

#endif //ED2023_EXPRESSION_H
