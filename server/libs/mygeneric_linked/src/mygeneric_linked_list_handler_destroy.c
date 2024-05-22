/*
** EPITECH PROJECT, 2024
** gen linked
** File description:
** destoy the handle and all it's associated nodes
*/
#include "../includes/mygeneric_linked_list.h"

void
mygeneric_linked_list_handler_destroy(mygeneric_linked_list_handler_t *handle,
    bool destroy_node, bool destroy_data)
{
    mygeneric_linked_list_t *it = handle->head;
    mygeneric_linked_list_t *tmp = NULL;

    if (handle == NULL)
        return;
    if (destroy_node == false)
        return free(handle);
    while (it != NULL) {
        tmp = it->next;
        mygeneric_linked_list_destroy(it, destroy_data);
        it = tmp;
    }
    return free(handle);
}
