#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include "../include/satisfiability.h"
#include "../include/tree.h"

using namespace std;

void Satisfiability::fillTree(string expression)
{
    BinaryTree myTree;
    myTree.insert(expression, 0);
    int numVariables = count(expression.begin(), expression.end(), 'e');
    int numCombinations = pow(2, numVariables);

    for(int combination = 0; combination < numCombinations; ++combination)
    {
        string tempExpression = expression;
        for(int i = 0; i < numVariables; ++i)
        {
            int bit = (combination >> (numVariables - 1 - i)) & 1;
            size_t pos = tempExpression.find('e');
            if(pos != string::npos)
            {
                tempExpression.replace(pos, 1, to_string(bit));
                myTree.insert(tempExpression, i+1);
            }
        }
    }
    verifySatisfiability(myTree);
}

void Satisfiability::verifySatisfiability(BinaryTree tree) {
    string teste = tree.getLastNodeValue();

    cout << teste << endl;
}