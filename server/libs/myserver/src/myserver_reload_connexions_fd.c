/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** reload every connexion_fd in fd_set
*/

#include "../includes/myserver.h"

void
myserver_reload_fd(myserver_t *serv)
{
    FD_ZERO(&(serv->_read));
    FD_ZERO(&(serv->_write));
    FD_SET(serv->fd, &(serv->_read));
    FD_SET(serv->fd, &(serv->_write));
    for (myconnexion_t *tmp = serv->connexion_list;
        tmp != NULL; tmp = tmp->next) {
        FD_SET(tmp->fd, &(serv->_read));
        if (tmp->reply_end_of_cmd_index != 0)
            FD_SET(tmp->fd, &(serv->_write));
    }
}
