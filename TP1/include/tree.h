#ifndef TREE_H
#define TREE_H

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {

    public:
        BinaryTree() : root(nullptr) {};
        void insert(int val);
        void inorderTraversal(TreeNode* node);
        void postorderTraversal(TreeNode* node);

    private:
        TreeNode* insertNode(TreeNode* node, int val);
        TreeNode* root;

};


#endif
