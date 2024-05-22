/*
** EPITECH PROJECT, 2024
** ftp lib
** File description:
** get the function associated to the key
*/

#include "../includes/myevent_handler.h"
#include <stddef.h>
#include <string.h>

void *
myevent_handler_get_function(myevent_handler_t *handler, const char *key)
{
    myevent_t *tmp = NULL;

    if (handler == NULL)
        return NULL;
    tmp = handler->event_list;
    for (; tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->cmd, key) == 0)
            return tmp->fun_ptr;
    }
    return NULL;
}
