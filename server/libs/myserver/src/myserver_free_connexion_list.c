/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** free serv / connexion struct
*/

#include "myserver.h"

void
myserver_free_connexion_list(myserver_t *serv)
{
    myconnexion_t *tmp = serv->connexion_list;
    myconnexion_t *death_sentence = NULL;

    while (tmp != NULL) {
        death_sentence = tmp;
        tmp = tmp->next;
        myconnexion_destroy(death_sentence);
    }
}
