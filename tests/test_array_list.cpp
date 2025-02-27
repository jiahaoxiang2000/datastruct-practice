#include <gtest/gtest.h>
#include "datastruct/array_list.h"

class ArrayListTest : public ::testing::Test
{
protected:
    ArrayList *list;

    void SetUp() override
    {
        list = array_list_create(5);
    }

    void TearDown() override
    {
        array_list_destroy(list);
    }
};

TEST_F(ArrayListTest, CreateEmptyList)
{
    EXPECT_EQ(array_list_size(list), 0);
    EXPECT_TRUE(array_list_is_empty(list));
}

TEST_F(ArrayListTest, AddElements)
{
    EXPECT_TRUE(array_list_add(list, 10));
    EXPECT_TRUE(array_list_add(list, 20));
    EXPECT_TRUE(array_list_add(list, 30));

    EXPECT_EQ(array_list_size(list), 3);
    EXPECT_FALSE(array_list_is_empty(list));
}

TEST_F(ArrayListTest, GetElement)
{
    array_list_add(list, 10);
    array_list_add(list, 20);
    array_list_add(list, 30);

    EXPECT_EQ(array_list_get(list, 0), 10);
    EXPECT_EQ(array_list_get(list, 1), 20);
    EXPECT_EQ(array_list_get(list, 2), 30);

    // Invalid index
    EXPECT_EQ(array_list_get(list, 3), -1);
    EXPECT_EQ(array_list_get(list, -1), -1);
}

TEST_F(ArrayListTest, SetElement)
{
    array_list_add(list, 10);
    array_list_add(list, 20);

    EXPECT_TRUE(array_list_set(list, 0, 15));
    EXPECT_TRUE(array_list_set(list, 1, 25));

    EXPECT_EQ(array_list_get(list, 0), 15);
    EXPECT_EQ(array_list_get(list, 1), 25);

    // Invalid index
    EXPECT_FALSE(array_list_set(list, 2, 30));
    EXPECT_FALSE(array_list_set(list, -1, 5));
}

TEST_F(ArrayListTest, RemoveElement)
{
    array_list_add(list, 10);
    array_list_add(list, 20);
    array_list_add(list, 30);

    EXPECT_TRUE(array_list_remove(list, 1));
    EXPECT_EQ(array_list_size(list), 2);
    EXPECT_EQ(array_list_get(list, 0), 10);
    EXPECT_EQ(array_list_get(list, 1), 30);

    // Invalid index
    EXPECT_FALSE(array_list_remove(list, 2));
    EXPECT_FALSE(array_list_remove(list, -1));
}

TEST_F(ArrayListTest, ContainsAndIndexOf)
{
    array_list_add(list, 10);
    array_list_add(list, 20);
    array_list_add(list, 30);

    EXPECT_TRUE(array_list_contains(list, 20));
    EXPECT_FALSE(array_list_contains(list, 40));

    EXPECT_EQ(array_list_index_of(list, 10), 0);
    EXPECT_EQ(array_list_index_of(list, 20), 1);
    EXPECT_EQ(array_list_index_of(list, 30), 2);
    EXPECT_EQ(array_list_index_of(list, 40), -1);
}

TEST_F(ArrayListTest, AutoResize)
{
    // Fill beyond initial capacity to trigger resize
    for (int i = 0; i < 10; i++)
    {
        EXPECT_TRUE(array_list_add(list, i * 10));
    }

    EXPECT_EQ(array_list_size(list), 10);

    // All elements should still be accessible
    for (int i = 0; i < 10; i++)
    {
        EXPECT_EQ(array_list_get(list, i), i * 10);
    }
}

TEST_F(ArrayListTest, Clear)
{
    array_list_add(list, 10);
    array_list_add(list, 20);
    array_list_add(list, 30);

    array_list_clear(list);

    EXPECT_EQ(array_list_size(list), 0);
    EXPECT_TRUE(array_list_is_empty(list));
}
