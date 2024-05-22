/*
** EPITECH PROJECT, 2024
** ftp lib
** File description:
** set server data
*/

#include "../includes/myserver.h"

void
myserver_set_data(myserver_t *server, void *data)
{
    server->data = data;
}

void *
myserver_get_data(myserver_t *server)
{
    return server->data;
}
