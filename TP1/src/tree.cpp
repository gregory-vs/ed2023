#include <iostream>
#include "../include/tree.h"
using namespace std;


void BinaryTree::insert(int val) {
    root = insertNode(root, val);
}

void BinaryTree::postorderTraversal(TreeNode* node) {
    if (node == nullptr) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " "; // return something
}

// Recursive function to insert a new node into the tree
TreeNode* BinaryTree::insertNode(TreeNode* node, int val) {
    if (node == nullptr) {
        return new TreeNode(val);
    }

    if (val < node->data) {
        node->left = insertNode(node->left, val);
    } else if (val > node->data) {
        node->right = insertNode(node->right, val);
    }

    return node;
}

