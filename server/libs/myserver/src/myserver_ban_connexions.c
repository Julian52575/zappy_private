/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** I have had enough
** you're getting banned from my ftp server for sending too much garbage data
** you idiot
*/

#include "../includes/myserver.h"

void
myserver_ban_connexions(myserver_t *serv)
{
    myconnexion_t *tmp = NULL;

    for (tmp = serv->connexion_list; tmp != NULL; tmp = tmp->next) {
        if (tmp->status != CL_BANNED)
            continue;
        myconnexion_remove_from_list(&(serv->connexion_list), tmp);
    }
}
