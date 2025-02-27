#include <gtest/gtest.h>
#include "datastruct/tree.h"

TEST(TreeTest, InsertAndSearch) {
    Tree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    EXPECT_TRUE(tree.search(10));
    EXPECT_TRUE(tree.search(5));
    EXPECT_TRUE(tree.search(15));
    EXPECT_FALSE(tree.search(20));
}

TEST(TreeTest, InOrderTraversal) {
    Tree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    
    std::vector<int> expected = {5, 10, 15};
    EXPECT_EQ(tree.inOrderTraversal(), expected);
}

TEST(TreeTest, DeleteNode) {
    Tree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.deleteNode(10);

    EXPECT_FALSE(tree.search(10));
    EXPECT_TRUE(tree.search(5));
    EXPECT_TRUE(tree.search(15));
}