#ifndef ED2023_SATISFIABILITY_H
#define ED2023_SATISFIABILITY_H
#include <string>
#include "../include/tree.h"


class Satisfiability {
    public:
        static void fillTree(std::string expression);
        static void verifySatisfiability(BinaryTree tree);

};


#endif
