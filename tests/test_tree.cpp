#include <gtest/gtest.h>
#include "datastruct/tree.h"

class TreeTest : public ::testing::Test
{
protected:
    Tree *tree;

    void SetUp() override
    {
        tree = create_tree();
    }

    void TearDown() override
    {
        free_tree(tree);
    }
};

TEST_F(TreeTest, CreateEmptyTree)
{
    EXPECT_EQ(tree->root, nullptr);
}

TEST_F(TreeTest, InsertAndSearch)
{
    insert(tree, 10);
    insert(tree, 5);
    insert(tree, 15);

    TreeNode *found = search(tree, 5);
    EXPECT_NE(found, nullptr);
    EXPECT_EQ(found->value, 5);

    found = search(tree, 99);
    EXPECT_EQ(found, nullptr);
}

TEST_F(TreeTest, InsertMultipleNodes)
{
    int values[] = {10, 5, 15, 3, 7, 12, 18};
    for (int val : values)
    {
        insert(tree, val);
    }

    for (int val : values)
    {
        TreeNode *found = search(tree, val);
        EXPECT_NE(found, nullptr);
        EXPECT_EQ(found->value, val);
    }
}