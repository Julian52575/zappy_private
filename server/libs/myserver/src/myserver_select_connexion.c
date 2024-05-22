/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** select connexion who connected to server since the function last call
*/

#include "myserver.h"

int
myserver_select_connexion(myserver_t *serv)
{
    int status = 0;
    int max_fd = serv->max_fd + 1;

    status = select(max_fd, &(serv->_read), &(serv->_write), NULL, NULL);
    if (status == -1)
        perror("Select:\t");
    return status;
}
