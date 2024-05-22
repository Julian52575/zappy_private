/*
** EPITECH PROJECT, 2024
** gen linked
** File description:
** find a node inside the handle
*/

#include "../includes/mygeneric_linked_list.h"
#include <uuid/uuid.h>

mygeneric_linked_list_t *
mygeneric_linked_list_handler_find_uuid(
    mygeneric_linked_list_handler_t *handle, uuid_t uuid)
{
    mygeneric_linked_list_t *it = handle->head;

    for (; it != NULL; it = it->next) {
        if (uuid_compare(it->uuid, uuid) == 0)
            return it;
    }
    return NULL;
}

mygeneric_linked_list_t *
mygeneric_linked_list_handler_find(mygeneric_linked_list_handler_t *handle,
    long id)
{
    mygeneric_linked_list_t *it = handle->head;

    for (; it != NULL; it = it->next) {
        if (it->id == id)
            return it;
    }
    return NULL;
}
