/*
** EPITECH PROJECT, 2024
** gen linked
** File description:
** delink a node from the previous node
*/

#include "../includes/mygeneric_linked_list.h"

static void
mygeneric_linked_list_delink_link(mygeneric_linked_list_t **node,
    mygeneric_linked_list_t *prev, mygeneric_linked_list_t *next)
{
    if (next) {
        next->prev = prev;
        if (prev)
            prev->next = next;
        (*node) = next;
    }
    if (prev) {
        prev->next = next;
        if (next)
            next->prev = prev;
        (*node) = prev;
    }
}

static void
mygeneric_linked_list_delink_reset_node(mygeneric_linked_list_t *node)
{
    node->prev = NULL;
    node->next = NULL;
}

void
mygeneric_linked_list_delink(mygeneric_linked_list_t **node, bool free_node)
{
    mygeneric_linked_list_t *tmp = *node;
    mygeneric_linked_list_t *prev = NULL;
    mygeneric_linked_list_t *next = NULL;

    if (*node == NULL)
        return;
    prev = (*node)->prev;
    next = (*node)->next;
    if (prev == NULL && next == NULL) {
        (*node) = NULL;
        return;
    }
    mygeneric_linked_list_delink_link(node, prev, next);
    mygeneric_linked_list_delink_reset_node(tmp);
    if (free_node == true && tmp != NULL)
        free(tmp);
}
