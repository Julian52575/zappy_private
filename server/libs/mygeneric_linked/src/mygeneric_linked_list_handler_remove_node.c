/*
** EPITECH PROJECT, 2024
** gen linked
** File description:
** remove a node from the handler
*/

#include "../includes/mygeneric_linked_list.h"
#include <uuid/uuid.h>

static void
mygeneric_linked_list_handler_destroy_single_node
    (mygeneric_linked_list_handler_t *handle,
    bool destroy_node, bool destroy_data)
{
    mygeneric_linked_list_t *tmp = handle->head;

    handle->head = NULL;
    handle->element = 0;
    if (destroy_node == true)
        mygeneric_linked_list_destroy(tmp, destroy_data);
}

static void
mygeneric_linked_list_handler_find_and_remove_uuid(
    mygeneric_linked_list_handler_t *handle,
    uuid_t uuid, bool destroy_node, bool destroy_data)
{
    mygeneric_linked_list_t *it = NULL;

    it = handle->head->next;
    while (it != NULL) {
        if (uuid_compare(it->uuid, uuid) != 0) {
            it = it->next;
            continue;
        }
        if (destroy_data == true && it->data)
            free(it->data);
        mygeneric_linked_list_delink(&it, destroy_node);
        handle->element -= 1;
        return;
    }
}

void
mygeneric_linked_list_handler_remove_node_uuid(
    mygeneric_linked_list_handler_t *handle, uuid_t uuid,
    bool destroy_node, bool destroy_data)
{
    if (handle->element == 0)
        return;
    if (handle->element == 1) {
        mygeneric_linked_list_handler_destroy_single_node(handle,
            destroy_node, destroy_data);
        return;
    }
    if (uuid_compare(handle->head->uuid, uuid) == 0) {
        mygeneric_linked_list_delink(&(handle->head), destroy_node);
        handle->element -= 1;
        return;
    }
    mygeneric_linked_list_handler_find_and_remove_uuid(handle,
        uuid, destroy_node, destroy_data);
}

static void
mygeneric_linked_list_handler_find_and_remove(
    mygeneric_linked_list_handler_t *handle,
    long id, bool destroy_node, bool destroy_data)
{
    mygeneric_linked_list_t *it = NULL;

    it = handle->head->next;
    while (it != NULL) {
        if (it->id != id) {
            it = it->next;
            continue;
        }
        if (destroy_data == true && it->data)
            free(it->data);
        mygeneric_linked_list_delink(&it, destroy_node);
        handle->element -= 1;
        return;
    }
}

void
mygeneric_linked_list_handler_remove_node(
    mygeneric_linked_list_handler_t *handle, long id,
    bool destroy_node, bool destroy_data)
{
    if (handle->element == 0)
        return;
    if (handle->element == 1) {
        mygeneric_linked_list_handler_destroy_single_node(handle,
            destroy_node, destroy_data);
        return;
    }
    if (handle->head->id == id) {
        mygeneric_linked_list_delink(&(handle->head), destroy_node);
        handle->element -= 1;
        return;
    }
    mygeneric_linked_list_handler_find_and_remove(handle,
        id, destroy_node, destroy_data);
}
