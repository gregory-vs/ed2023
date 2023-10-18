#ifndef TREE_H
#define TREE_H
#include <string>

struct TreeNode {
    std::string data;
    int pos;
    TreeNode* left;
    TreeNode* right;

    TreeNode(std::string val, int n) : data(val), pos(n), left(nullptr), right(nullptr) {}
};

class BinaryTree {

    public:
        BinaryTree() : root(nullptr) {};
        ~BinaryTree();
        void insert(const std::string& val, const int& pos);
        static std::string postorderTraversal(TreeNode* node);
        static bool isSubtreeFull(TreeNode* node);
        TreeNode* getRoot() {return root;}
        std::string getLastNodeValue();

    private:
        TreeNode* insertRecursive(TreeNode* node, const std::string& val, const int& pos);
        void destroyTree(TreeNode* node);
        TreeNode* root;

};


#endif
