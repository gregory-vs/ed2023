#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include "../include/stack.h"
#include "../include/node.h"

using namespace std;

int obterPrecedencia(char operador) {
    map<char, int> precedencia;
    precedencia['+'] = 1;
    precedencia['-'] = 1;
    precedencia['*'] = 2;
    precedencia['/'] = 2;
    return precedencia[operador];
}

string infixParaRPN(string expressao) {
    Stack operadores;
    string resultado;

    for (char token : expressao) {
        if (isdigit(token)) {
            // Se for um dígito, adiciona ao resultado
            resultado += token;
        } else if (token == '(') {
            // Se for um parêntese de abertura, empilha na pilha de operadores
            operadores.push(new NodeOperator(token, nullptr, nullptr));
        } else if (token == ')') {
            // Se for um parêntese de fechamento, desempilha operadores até encontrar o parêntese de abertura
            while (operadores.getTop() != nullptr && operadores.getTop()->evaluate() != '(') {
                resultado += operadores.getTop()->evaluate();
                operadores.pop();
            }
            // Remove o parêntese de abertura da pilha
            operadores.pop();
        } else if (isspace(token)) {
            // Ignora espaços em branco
            continue;
        } else {
            // Se for um operador, desempilha operadores de maior ou igual precedência e depois empilha o operador atual
            while (operadores.getTop() != nullptr && operadores.getTop()->evaluate() != '(' && obterPrecedencia(operadores.getTop()->evaluate()) >= obterPrecedencia(token)) {
                resultado += operadores.getTop()->evaluate();
                operadores.pop();
            }
            operadores.push(new NodeOperator(token, nullptr, nullptr));
        }
    }

    // Desempilha os operadores restantes e adiciona ao resultado
    while (operadores.getTop() != nullptr) {
        resultado += operadores.getTop()->evaluate();
        operadores.pop();
    }

    return resultado;
}