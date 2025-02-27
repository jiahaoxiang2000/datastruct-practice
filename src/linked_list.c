#include <stdio.h>
#include <stdlib.h>
#include "datastruct/linked_list.h"

LinkedList *create_linked_list()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

void add_node(LinkedList *list, int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
}

void remove_node(LinkedList *list, int data)
{
    Node *current = list->head;
    Node *previous = NULL;

    while (current != NULL && current->data != data)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
        return; // Data not found

    if (previous == NULL)
    {
        list->head = current->next; // Remove head
    }
    else
    {
        previous->next = current->next; // Bypass the current node
    }

    free(current);
}

void traverse_list(LinkedList *list)
{
    Node *current = list->head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void free_linked_list(LinkedList *list)
{
    Node *current = list->head;
    Node *next_node;

    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    free(list);
}