#include "../include/datastruct/queue.h"
#include <stdlib.h>
#include <assert.h>

struct QueueNode
{
    int data;
    QueueNode *next;
};

struct Queue
{
    QueueNode *front;
    QueueNode *rear;
};

Queue *queue_create()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (queue)
    {
        queue->front = NULL;
        queue->rear = NULL;
    }
    return queue;
}

void queue_destroy(Queue *queue)
{
    if (!queue)
        return;

    QueueNode *current = queue->front;
    QueueNode *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    free(queue);
}

void queue_enqueue(Queue *queue, int value)
{
    assert(queue != NULL);

    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (!newNode)
        return;

    newNode->data = value;
    newNode->next = NULL;

    if (queue->rear == NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int queue_dequeue(Queue *queue)
{
    assert(queue != NULL);
    assert(queue->front != NULL); // Queue is not empty

    QueueNode *temp = queue->front;
    int value = temp->data;

    queue->front = queue->front->next;

    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    free(temp);
    return value;
}

int queue_is_empty(const Queue *queue)
{
    assert(queue != NULL);
    return queue->front == NULL;
}