#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* top;

public:
    Stack();
    ~Stack();
    void push(const T& value);
    void pop();
    T peek() const;
    bool isEmpty() const;
};

#include "stack.inl"

#endif // STACK_H