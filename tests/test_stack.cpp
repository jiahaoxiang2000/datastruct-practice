#include <gtest/gtest.h>
#include "datastruct/stack.h"

TEST(StackTest, PushAndPop) {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    EXPECT_EQ(stack.pop(), 2);
    EXPECT_EQ(stack.pop(), 1);
}

TEST(StackTest, IsEmpty) {
    Stack<int> stack;
    EXPECT_TRUE(stack.isEmpty());
    stack.push(1);
    EXPECT_FALSE(stack.isEmpty());
    stack.pop();
    EXPECT_TRUE(stack.isEmpty());
}

TEST(StackTest, PopEmptyStack) {
    Stack<int> stack;
    EXPECT_THROW(stack.pop(), std::out_of_range);
}