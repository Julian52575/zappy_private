/*
** EPITECH PROJECT, 2024
** ftp lib
** File description:
** free everything related to the event handler struct
*/

#include "../includes/myserver.h"

void
myevent_handler_destroy(myevent_handler_t *handle)
{
    myevent_t *death = NULL;
    myevent_t *tmp = handle->event_list;

    while (tmp != NULL) {
        death = tmp;
        tmp = tmp->next;
        free(death);
    }
    free(handle);
}
