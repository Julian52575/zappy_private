/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** myserver stop
*/

#include "myserver.h"

void
myserver_stop(myserver_t *serv)
{
    serv->running = false;
    return;
}
