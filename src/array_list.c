#include "datastruct/array_list.h"
#include <stdlib.h>
#include <string.h>

#define DEFAULT_CAPACITY 10
#define GROWTH_FACTOR 1.5

ArrayList *array_list_create(int initial_capacity)
{
    ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));
    if (!list)
    {
        return NULL;
    }

    if (initial_capacity <= 0)
    {
        initial_capacity = DEFAULT_CAPACITY;
    }

    list->data = (int *)malloc(sizeof(int) * initial_capacity);
    if (!list->data)
    {
        free(list);
        return NULL;
    }

    list->size = 0;
    list->capacity = initial_capacity;
    return list;
}

void array_list_destroy(ArrayList *list)
{
    if (list)
    {
        free(list->data);
        free(list);
    }
}

int array_list_ensure_capacity(ArrayList *list, int min_capacity)
{
    if (!list || min_capacity <= list->capacity)
    {
        return 0;
    }

    int new_capacity = (int)(list->capacity * GROWTH_FACTOR);
    if (new_capacity < min_capacity)
    {
        new_capacity = min_capacity;
    }

    int *new_data = (int *)realloc(list->data, sizeof(int) * new_capacity);
    if (!new_data)
    {
        return 0;
    }

    list->data = new_data;
    list->capacity = new_capacity;
    return 1;
}

int array_list_add(ArrayList *list, int value)
{
    if (!list)
    {
        return 0;
    }

    if (list->size >= list->capacity)
    {
        if (!array_list_ensure_capacity(list, list->capacity + 1))
        {
            return 0;
        }
    }

    list->data[list->size++] = value;
    return 1;
}

int array_list_get(ArrayList *list, int index)
{
    if (!list || index < 0 || index >= list->size)
    {
        // Return a sentinel value for error
        return -1;
    }

    return list->data[index];
}

int array_list_set(ArrayList *list, int index, int value)
{
    if (!list || index < 0 || index >= list->size)
    {
        return 0;
    }

    list->data[index] = value;
    return 1;
}

int array_list_remove(ArrayList *list, int index)
{
    if (!list || index < 0 || index >= list->size)
    {
        return 0;
    }

    // Shift elements to fill the gap
    for (int i = index; i < list->size - 1; i++)
    {
        list->data[i] = list->data[i + 1];
    }

    list->size--;
    return 1;
}

int array_list_contains(ArrayList *list, int value)
{
    return array_list_index_of(list, value) != -1;
}

int array_list_index_of(ArrayList *list, int value)
{
    if (!list)
    {
        return -1;
    }

    for (int i = 0; i < list->size; i++)
    {
        if (list->data[i] == value)
        {
            return i;
        }
    }

    return -1;
}

int array_list_size(ArrayList *list)
{
    return list ? list->size : 0;
}

int array_list_is_empty(ArrayList *list)
{
    return list ? list->size == 0 : 1;
}

void array_list_clear(ArrayList *list)
{
    if (list)
    {
        list->size = 0;
    }
}
