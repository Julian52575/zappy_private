/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** add new connexion to the server connexion
*/
#include "../includes/myserver.h"
#include "../includes/myconnexion.h"
#include <stdbool.h>

int
myserver_add_connexion(myserver_t *serv,
    int connexion_fd, struct sockaddr_in *config)
{
    myconnexion_t *connexion = myconnexion_init(connexion_fd, config,
        serv->default_delimiters, serv->delimiters_length);

    if (connexion == NULL)
        return -1;
    if (serv->welcome_msg != NULL && serv->welcome_length > 0) {
        myconnexion_add_in_reply_buffer(connexion,
            serv->welcome_msg, serv->welcome_length, true);
    }
    if (connexion->fd > serv->max_fd)
        serv->max_fd = connexion->fd;
    myconnexion_link(&(serv->connexion_list), connexion);
    return 0;
}
