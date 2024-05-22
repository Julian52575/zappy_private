/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** reply (read) to connexion sending packets
*/

#include "../includes/myserver.h"

//FD_ISSET sur liste chainée
int
myserver_reply_to_connexions(myserver_t *serv)
{
    int status = 0;

    for (myconnexion_t *tmp = serv->connexion_list;
        tmp != NULL; tmp = tmp->next) {
        if (status == -1)
            break;
        if (FD_ISSET(tmp->fd, &(serv->_write)) == 0) {
            continue;
        }
        status = myconnexion_write_reply_buffer(tmp);
    }
    return status;
}
