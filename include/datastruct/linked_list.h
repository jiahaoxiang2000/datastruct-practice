#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#ifdef __cplusplus
extern "C"
{
#endif
#include <stddef.h>

    typedef struct Node
    {
        int data;
        struct Node *next;
    } Node;

    typedef struct LinkedList
    {
        Node *head;
    } LinkedList;

    LinkedList *create_linked_list();
    void add_node(LinkedList *list, int data);
    void remove_node(LinkedList *list, int data);
    void traverse_list(LinkedList *list);
    void free_linked_list(LinkedList *list);
#ifdef __cplusplus
}
#endif
#endif // LINKED_LIST_H