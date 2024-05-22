/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** Listent to connexion's input and store them in their respective buffers
*/

#include "../includes/myserver.h"

int
myserver_listen_to_connexions(myserver_t *serv)
{
    int status = 0;

    for (myconnexion_t *tmp = serv->connexion_list;
        tmp != NULL; tmp = tmp->next) {
        if (status == -84)
            break;
        if (FD_ISSET(tmp->fd, &(serv->_read)) == 0) {
            continue;
        }
        status = myconnexion_read_packets(tmp);
    }
    return status;
}
