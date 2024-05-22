/*
** EPITECH PROJECT, 2024
** gen linked
** File description:
** add a node to the handler
*/

#include "../includes/mygeneric_linked_list.h"
#include <uuid/uuid.h>

int
mygeneric_linked_list_handler_add_node(mygeneric_linked_list_handler_t *handle,
    void *data, long id, uuid_t uuid)
{
    mygeneric_linked_list_t *node = mygeneric_linked_list_init(data, id);

    if (node == NULL)
        return -1;
    mygeneric_linked_list_set_uuid(node, uuid);
    mygeneric_linked_list_link(&(handle->head), node);
    handle->element += 1;
    return 0;
}
