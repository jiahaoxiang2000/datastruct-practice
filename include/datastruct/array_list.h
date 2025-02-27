#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct ArrayList
    {
        int *data;
        int size;
        int capacity;
    } ArrayList;

    ArrayList *array_list_create(int initial_capacity);
    void array_list_destroy(ArrayList *list);
    int array_list_add(ArrayList *list, int value);
    int array_list_get(ArrayList *list, int index);
    int array_list_set(ArrayList *list, int index, int value);
    int array_list_remove(ArrayList *list, int index);
    int array_list_contains(ArrayList *list, int value);
    int array_list_index_of(ArrayList *list, int value);
    int array_list_size(ArrayList *list);
    int array_list_is_empty(ArrayList *list);
    void array_list_clear(ArrayList *list);
    int array_list_ensure_capacity(ArrayList *list, int min_capacity);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_LIST_H
