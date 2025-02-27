#include <gtest/gtest.h>
#include "datastruct/linked_list.h"

class LinkedListTest : public ::testing::Test {
protected:
    LinkedList<int>* list;

    void SetUp() override {
        list = new LinkedList<int>();
    }

    void TearDown() override {
        delete list;
    }
};

TEST_F(LinkedListTest, AddNode) {
    list->add(1);
    EXPECT_EQ(list->get(0), 1);
}

TEST_F(LinkedListTest, RemoveNode) {
    list->add(1);
    list->remove(1);
    EXPECT_THROW(list->get(0), std::out_of_range);
}

TEST_F(LinkedListTest, TraverseList) {
    list->add(1);
    list->add(2);
    std::vector<int> expected = {1, 2};
    EXPECT_EQ(list->traverse(), expected);
}

TEST_F(LinkedListTest, SizeOfList) {
    EXPECT_EQ(list->size(), 0);
    list->add(1);
    EXPECT_EQ(list->size(), 1);
    list->add(2);
    EXPECT_EQ(list->size(), 2);
}