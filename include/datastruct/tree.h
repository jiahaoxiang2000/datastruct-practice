#ifndef TREE_H
#define TREE_H

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class Tree {
public:
    TreeNode* root;

    Tree() : root(nullptr) {}

    void insert(int value);
    bool search(int value);
    void inorderTraversal(TreeNode* node);
    void preorderTraversal(TreeNode* node);
    void postorderTraversal(TreeNode* node);
};

#endif // TREE_H