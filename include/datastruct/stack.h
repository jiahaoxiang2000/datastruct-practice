#ifndef STACK_H
#define STACK_H
#ifdef __cplusplus
extern "C"
{
#endif
    typedef struct Stack
    {
        int top;
        int capacity;
        int *array;
    } Stack;

    Stack *createStack(int capacity);
    void freeStack(Stack *stack);
    int isFull(Stack *stack);
    int isEmpty(Stack *stack);
    void push(Stack *stack, int item);
    int pop(Stack *stack);
    int peek(Stack *stack);

#ifdef __cplusplus
}
#endif
#endif // STACK_H