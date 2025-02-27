#include "datastruct/tree.h"
#include <stdlib.h>
#include <stdio.h>

struct Tree *create_tree()
{
    struct Tree *tree = (struct Tree *)malloc(sizeof(struct Tree));
    tree->root = NULL;
    return tree;
}

struct TreeNode *insert_node(struct TreeNode *node, int value)
{
    if (node == NULL)
    {
        struct TreeNode *new_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        new_node->value = value;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    if (value < node->value)
    {
        node->left = insert_node(node->left, value);
    }
    else
    {
        node->right = insert_node(node->right, value);
    }
    return node;
}

void insert(struct Tree *tree, int value)
{
    tree->root = insert_node(tree->root, value);
}

void inorder_traversal(struct TreeNode *node)
{
    if (node != NULL)
    {
        inorder_traversal(node->left);
        printf("%d ", node->value);
        inorder_traversal(node->right);
    }
}

void traverse(struct Tree *tree)
{
    inorder_traversal(tree->root);
}

struct TreeNode *search_node(struct TreeNode *node, int value)
{
    if (node == NULL || node->value == value)
    {
        return node;
    }
    if (value < node->value)
    {
        return search_node(node->left, value);
    }
    return search_node(node->right, value);
}

struct TreeNode *search(struct Tree *tree, int value)
{
    return search_node(tree->root, value);
}

void free_tree_node(struct TreeNode *node)
{
    if (node != NULL)
    {
        free_tree_node(node->left);
        free_tree_node(node->right);
        free(node);
    }
}

void free_tree(struct Tree *tree)
{
    free_tree_node(tree->root);
    free(tree);
}