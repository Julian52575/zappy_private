/*
** EPITECH PROJECT, 2024
** gen linked
** File description:
** init handler
*/

#include "../includes/mygeneric_linked_list.h"
#include <stdlib.h>

mygeneric_linked_list_handler_t *
mygeneric_linked_list_handler_init(void)
{
    mygeneric_linked_list_handler_t *handle =
        malloc(sizeof(mygeneric_linked_list_handler_t));

    if (handle == NULL)
        return NULL;
    handle->element = 0;
    handle->head = NULL;
    return handle;
}
