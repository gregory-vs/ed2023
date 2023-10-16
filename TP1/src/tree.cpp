#include <iostream>
#include "../include/tree.h"
using namespace std;


void BinaryTree::insert(int val) {
    root = insertNode(root, val);
}

// Function to perform an in-order traversal of the tree
void BinaryTree::inorderTraversal(TreeNode* node) {
    if (node == nullptr) return;
    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

// Function to perform a post-order traversal of the tree
void BinaryTree::postorderTraversal(TreeNode* node) {
    if (node == nullptr) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " ";
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

