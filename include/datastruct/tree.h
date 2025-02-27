#ifndef TREE_H
#define TREE_H
#ifdef __cplusplus
extern "C"
{
#endif
    struct TreeNode
    {
        int value;
        struct TreeNode *left;
        struct TreeNode *right;
    };

    struct Tree
    {
        struct TreeNode *root;
    };

    struct Tree *create_tree();
    void free_tree(struct Tree *tree);
    void insert(struct Tree *tree, int value);
    struct TreeNode *search(struct Tree *tree, int value);
    void traverse(struct Tree *tree);
#ifdef __cplusplus
}
#endif
#endif // TREE_H