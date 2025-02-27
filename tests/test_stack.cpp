#include <gtest/gtest.h>
#include "../include/datastruct/stack.h"

class StackTest : public ::testing::Test
{
protected:
    Stack *stack;

    void SetUp() override
    {
        stack = createStack(5);
    }

    void TearDown() override
    {
        freeStack(stack);
    }
};

TEST_F(StackTest, CreateEmptyStack)
{
    EXPECT_TRUE(isEmpty(stack));
    EXPECT_FALSE(isFull(stack));
}

TEST_F(StackTest, PushAndPeek)
{
    push(stack, 10);
    EXPECT_EQ(peek(stack), 10);
    EXPECT_FALSE(isEmpty(stack));
}

TEST_F(StackTest, PushAndPop)
{
    push(stack, 10);
    push(stack, 20);
    EXPECT_EQ(pop(stack), 20);
    EXPECT_EQ(pop(stack), 10);
    EXPECT_TRUE(isEmpty(stack));
}

TEST_F(StackTest, FullStack)
{
    for (int i = 0; i < 5; i++)
    {
        push(stack, i);
    }
    EXPECT_TRUE(isFull(stack));
    push(stack, 100); // Should not add this item
    EXPECT_EQ(peek(stack), 4);
}