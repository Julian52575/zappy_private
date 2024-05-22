/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** Add new connexion to list if new connexion
*/

#include "myserver.h"

int
myserver_accept_new_connexion(myserver_t *serv)
{
    struct sockaddr_in config = {0};
    socklen_t size = sizeof(struct sockaddr_in);
    int connexion_fd = 0;

    if (FD_ISSET(serv->fd, &(serv->_read)) == 0)
        return 0;
    connexion_fd = accept(serv->fd, (struct sockaddr *) &config, &size);
    if (connexion_fd == -1) {
        perror("Accept");
        return -1;
    }
    myserver_add_connexion(serv, connexion_fd, &config);
    return 0;
}
