/*
** EPITECH PROJECT, 2024
** network lib
** File description:
** destroy myserver
*/
#include "../includes/myserver.h"
#include "myevent_handler.h"

void
myserver_destroy(myserver_t **serv)
{
    if (!serv || !(*serv))
        return;
    myserver_free_connexion_list(*serv);
    myevent_handler_destroy((*serv)->event_handler);
    close((*serv)->fd);
    free(*serv);
    *serv = NULL;
    return;
}
