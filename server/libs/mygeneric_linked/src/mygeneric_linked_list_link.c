/*
** EPITECH PROJECT, 2024
** gen linke
** File description:
** link a node to the list (LIFO)
*/

#include "../includes/mygeneric_linked_list.h"

void
mygeneric_linked_list_link(mygeneric_linked_list_t **list,
    mygeneric_linked_list_t *node)
{
    mygeneric_linked_list_t *tmp = NULL;

    if (*list == NULL) {
        *list = node;
        return;
    }
    node->next = *list;
    (*list)->prev = node;
    *list = node;
}
