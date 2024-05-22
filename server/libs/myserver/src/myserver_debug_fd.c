/*
** EPITECH PROJECT, 2024
** myserver_debug_fd.c
** File description:
** Debug both fds
*/

#include "../includes/myserver.h"

void
myserver_debug_fd(myserver_t *serv)
{
    printf("Debug]\tServer fd:\n");
    if (FD_ISSET(serv->fd, &(serv->_read)) != 0)
        printf("\tServer FD set in Read set\n");
    else
        printf("\tServer FD NOT set in Read set\n");
    for (myconnexion_t *tmp = serv->connexion_list;
        tmp != NULL; tmp = tmp->next) {
        printf("\t\tRead:\t_%d_\n", tmp->fd);
    }
    if (FD_ISSET(serv->fd, &(serv->_write)) != 0)
        printf("\tServer FD set in Write set\n");
    else
        printf("\tServer FD NOT set in Write set\n");
    for (myconnexion_t *tmp = serv->connexion_list;
        tmp != NULL; tmp = tmp->next) {
        printf("\t\tWrite:\t_%d_\n", tmp->fd);
    }
}
