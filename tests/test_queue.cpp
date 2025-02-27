#include <gtest/gtest.h>
#include "../include/datastruct/queue.h"

// Test fixture for queue tests
class QueueTest : public ::testing::Test
{
protected:
    Queue *queue;

    void SetUp() override
    {
        // Set up a new queue before each test
        queue = queue_create();
    }

    void TearDown() override
    {
        // Clean up after each test
        queue_destroy(queue);
    }
};

// Test that a new queue is empty
TEST_F(QueueTest, NewQueueIsEmpty)
{
    EXPECT_TRUE(queue_is_empty(queue));
}

// Test enqueuing a single element
TEST_F(QueueTest, EnqueueSingleElement)
{
    queue_enqueue(queue, 42);
    EXPECT_FALSE(queue_is_empty(queue));
}

// Test dequeuing an element
TEST_F(QueueTest, DequeueElement)
{
    queue_enqueue(queue, 42);
    int value = queue_dequeue(queue);
    EXPECT_EQ(value, 42);
    EXPECT_TRUE(queue_is_empty(queue));
}

// Test FIFO ordering
TEST_F(QueueTest, FIFOOrder)
{
    queue_enqueue(queue, 1);
    queue_enqueue(queue, 2);
    queue_enqueue(queue, 3);

    EXPECT_EQ(queue_dequeue(queue), 1);
    EXPECT_EQ(queue_dequeue(queue), 2);
    EXPECT_EQ(queue_dequeue(queue), 3);
    EXPECT_TRUE(queue_is_empty(queue));
}

// Test multiple operations
TEST_F(QueueTest, MultipleOperations)
{
    queue_enqueue(queue, 10);
    queue_enqueue(queue, 20);
    EXPECT_EQ(queue_dequeue(queue), 10);

    queue_enqueue(queue, 30);
    EXPECT_EQ(queue_dequeue(queue), 20);
    EXPECT_EQ(queue_dequeue(queue), 30);
    EXPECT_TRUE(queue_is_empty(queue));

    queue_enqueue(queue, 40);
    EXPECT_FALSE(queue_is_empty(queue));
    EXPECT_EQ(queue_dequeue(queue), 40);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}