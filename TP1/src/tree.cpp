#include <iostream>
#include <string>
#include "../include/tree.h"
using namespace std;


void BinaryTree::insert(const std::string& val, const int& pos)
{
    root = insertRecursive(root, val, pos);
}

TreeNode* BinaryTree::insertRecursive(TreeNode* node, const string& val, const int& pos) {
    if(node == nullptr)
        return new TreeNode(val, pos);
    else if((node->left == nullptr && node->right == nullptr) || node->left->data != val)
    {

        if(node->left != nullptr && node->left->pos == pos)
        {
            node->right = insertRecursive(node->right, val, pos);
        }
        if(pos > node->pos)
        {
            node->left = insertRecursive(node->left, val, pos);
        }
        else
            node->right = insertRecursive(node->right, val, pos);
    }
    return node;
}

bool BinaryTree::isSubtreeFull(TreeNode* node) {
    return node!= nullptr && node->left != nullptr && node->right != nullptr;
}


string BinaryTree::postorderTraversal(TreeNode* node) {
    if (node == nullptr) return "";
    string leftResult = postorderTraversal(node->left);
    string rightResult = postorderTraversal(node->right);

    if(leftResult.empty() && rightResult.empty())
        return node->data;
    else
        return leftResult + " " + rightResult;
}

string BinaryTree::getLastNodeValue(){
    string result = postorderTraversal(root);
    if(!result.empty())
        return result;
}

void BinaryTree::destroyTree(TreeNode *node) {
    if (node == nullptr) {
        return;
    }

    destroyTree(node->left);
    destroyTree(node->right);

    delete node;
}

BinaryTree::~BinaryTree()
{
    destroyTree(root);
}

