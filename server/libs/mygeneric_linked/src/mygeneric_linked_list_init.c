/*
** EPITECH PROJECT, 2024
** generic linked
** File description:
** init a instance of gen linked
*/

#include "../includes/mygeneric_linked_list.h"
#include <uuid/uuid.h>

mygeneric_linked_list_t *
mygeneric_linked_list_init(void *data, long id)
{
    mygeneric_linked_list_t *node = malloc(sizeof(mygeneric_linked_list_t));

    if (node == NULL)
        return NULL;
    node->data = data;
    node->id = id;
    for (int i = 0; i < 16; i++)
        node->uuid[i] = 0;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
