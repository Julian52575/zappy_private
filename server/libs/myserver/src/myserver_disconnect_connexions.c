/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** remove the disconnected and banned connexions
*/

#include "../includes/myserver.h"

void
myserver_disconnect_connexions(myserver_t *serv)
{
    myconnexion_t *tmp = NULL;

    for (tmp = serv->connexion_list; tmp != NULL; tmp = tmp->next) {
        if (tmp->status != CL_DISCONNECTED)
            continue;
        if (tmp->reply_end_of_cmd_index > 0)
            continue;
        myconnexion_remove_from_list(&(serv->connexion_list), tmp);
    }
}
