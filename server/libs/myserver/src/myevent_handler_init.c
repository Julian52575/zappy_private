/*
** EPITECH PROJECT, 2024
** ftp lib
** File description:
** create the server event handler
*/

#include "../includes/myserver.h"
#include <stdlib.h>

myevent_handler_t *
myevent_handler_init(void)
{
    myevent_handler_t *new = malloc(sizeof(myevent_handler_t));

    if (new == NULL)
        return NULL;
    new->event_list = NULL;
    return new;
}
