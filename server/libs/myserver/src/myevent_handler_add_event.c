/*
** EPITECH PROJECT, 2024
** ftp lib
** File description:
** add an event to the event list
*/

#include "../includes/myserver.h"
#include <stdlib.h>

static void
myevent_link_nodes(myevent_t **list, myevent_t *new)
{
    new->next = *list;
    *list = new;
    return;
}

int
myevent_handler_add_event(myevent_handler_t *handler,
    const char *name, void *function_ptr)
{
    myevent_t *new = NULL;

    if (name == NULL || function_ptr == NULL)
        return -1;
    if (myevent_handler_get_function(handler, name) != NULL)
        return 0;
    new = malloc(sizeof(myevent_t));
    if (new == NULL)
        return -84;
    new->cmd = name;
    new->fun_ptr = function_ptr;
    myevent_link_nodes(&(handler->event_list), new);
    return 0;
}
