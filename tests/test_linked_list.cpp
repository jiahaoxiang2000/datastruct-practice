#include <gtest/gtest.h>
#include "datastruct/linked_list.h"

class LinkedListTest : public ::testing::Test {
protected:
    LinkedList* list;

    void SetUp() override {
        list = create_linked_list();
    }

    void TearDown() override {
        free_linked_list(list);
    }
};

TEST_F(LinkedListTest, CreateEmptyList) {
    EXPECT_EQ(list->head, nullptr);
}

TEST_F(LinkedListTest, AddNode) {
    add_node(list, 5);
    EXPECT_EQ(list->head->data, 5);
    EXPECT_EQ(list->head->next, nullptr);

    add_node(list, 10);
    EXPECT_EQ(list->head->data, 10);
    EXPECT_EQ(list->head->next->data, 5);
}

TEST_F(LinkedListTest, RemoveNode) {
    add_node(list, 5);
    add_node(list, 10);
    add_node(list, 15);

    remove_node(list, 10);
    EXPECT_EQ(list->head->data, 15);
    EXPECT_EQ(list->head->next->data, 5);
}

TEST_F(LinkedListTest, RemoveNonExistentNode) {
    add_node(list, 5);
    remove_node(list, 10);
    EXPECT_EQ(list->head->data, 5);
}