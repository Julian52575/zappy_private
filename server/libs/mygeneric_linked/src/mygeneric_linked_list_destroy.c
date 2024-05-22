/*
** EPITECH PROJECT, 2024
** gen linked
** File description:
** free the node passed as a parameters
*/

#include "../includes/mygeneric_linked_list.h"

void
mygeneric_linked_list_destroy(mygeneric_linked_list_t *node,
    bool destroy_data)
{
    if (destroy_data == true && node->data != NULL)
        free(node->data);
    free(node);
}
