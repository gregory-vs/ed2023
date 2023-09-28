#include <iostream>
#include "../include/stack.h"
#include "../include/expressao.h"

// Função para verificar se um caractere é um operador
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Função para calcular o resultado da expressão
double evaluateExpression(string expression) {
    Stack numbers;
    Stack operators;

    for (int i = 0; i < expression.length(); i++) {
        char currentChar = expression[i];

        if (isspace(currentChar)) {
            continue; // Ignorar espaços em branco
        }

        if (isdigit(currentChar)) {
            string numStr;
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                numStr += expression[i];
                i++;
            }
            i--;

            double number = stod(numStr);
            numbers.push(number);
        } else if (isOperator(currentChar)) {
            while (!operators.isEmpty() && operators.top != '(' &&
                   ((currentChar == '+' || currentChar == '-') ||
                    (currentChar == '*' || currentChar == '/') && (operators.top() == '*' || operators.top() == '/'))) {
                double operand2 = numbers.top();
                numbers.pop();
                double operand1 = numbers.top();
                numbers.pop();
                char op = operators.top();
                operators.pop();

                double result;
                if (op == '+') {
                    result = operand1 + operand2;
                } else if (op == '-') {
                    result = operand1 - operand2;
                } else if (op == '*') {
                    result = operand1 * operand2;
                } else if (op == '/') {
                    if (operand2 == 0) {
                        cerr << "Erro: Divisão por zero." << endl;
                        exit(1);
                    }
                    result = operand1 / operand2;
                }
                numbers.push(result);
            }
            operators.push(currentChar);
        } else if (currentChar == '(') {
            operators.push(currentChar);
        } else if (currentChar == ')') {
            while (!operators.empty() && operators.top() != '(') {
                double operand2 = numbers.top();
                numbers.pop();
                double operand1 = numbers.top();
                numbers.pop();
                char op = operators.top();
                operators.pop();

                double result;
                if (op == '+') {
                    result = operand1 + operand2;
                } else if (op == '-') {
                    result = operand1 - operand2;
                } else if (op == '*') {
                    result = operand1 * operand2;
                } else if (op == '/') {
                    if (operand2 == 0) {
                        cerr << "Erro: Divisão por zero." << endl;
                        exit(1);
                    }
                    result = operand1 / operand2;
                }
                numbers.push(result);
            }
            if (!operators.empty() && operators.top() == '(') {
                operators.pop(); // Remover o '(' correspondente
            } else {
                cerr << "Erro: Expressão mal formada." << endl;
                exit(1);
            }
        } else {
            cerr << "Erro: Caractere inválido na expressão." << endl;
            exit(1);
        }
    }

    while (!operators.empty()) {
        if (operators.top() == '(') {
            cerr << "Erro: Expressão mal formada." << endl;
            exit(1);
        }
        double operand2 = numbers.top();
        numbers.pop();
        double operand1 = numbers.top();
        numbers.pop();
        char op = operators.top();
        operators.pop();

        double result;
        if (op == '+') {
            result = operand1 + operand2;
        } else if (op == '-') {
            result = operand1 - operand2;
        } else if (op == '*') {
            result = operand1 * operand2;
        } else if (op == '/') {
            if (operand2 == 0) {
                cerr << "Erro: Divisão por zero." << endl;
                exit(1);
            }
            result = operand1 / operand2;
        }
        numbers.push(result);
    }

    if (numbers.size() == 1) {
        return numbers.top();
    } else {
        cerr << "Erro: Expressão mal formada." << endl;
        exit(1);
    }
}

int main() {
    string expression;
    cout << "Digite uma expressão numérica: ";
    getline(cin, expression);

    double result = evaluateExpression(expression);
    cout << "Resultado: " << result << endl;

    return 0;
}
