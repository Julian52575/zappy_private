/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** update myserver_t max_fd var
*/

#include "myserver.h"

void myserver_update_max_fd(myserver_t *serv)
{
    myconnexion_t *tmp = NULL;

    for (tmp = serv->connexion_list; tmp != NULL; tmp = tmp->next) {
        if (tmp->fd > serv->max_fd) {
            serv->max_fd = tmp->fd;
        }
    }
}
