#ifndef QUEUE_H
#define QUEUE_H

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct QueueNode QueueNode;
    typedef struct Queue Queue;

    // Create a new queue
    Queue *queue_create();

    // Delete the queue and free all memory
    void queue_destroy(Queue *queue);

    // Add an element to the queue
    void queue_enqueue(Queue *queue, int value);

    // Remove and return the front element from the queue
    int queue_dequeue(Queue *queue);

    // Check if the queue is empty
    int queue_is_empty(const Queue *queue);

#ifdef __cplusplus
}
#endif

#endif // QUEUE_H