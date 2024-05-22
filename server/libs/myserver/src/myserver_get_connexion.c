/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** getter for myconnexion_t struct in myserver_t
*/

#include "../includes/myserver.h"

myconnexion_t *
myserver_get_connexion_by_fd(myserver_t *serv, int connexion_fd)
{
    for (myconnexion_t *tmp = serv->connexion_list;
        tmp != NULL; tmp = tmp->next) {
        if (tmp->fd == connexion_fd)
            return tmp;
    }
    return NULL;
}
