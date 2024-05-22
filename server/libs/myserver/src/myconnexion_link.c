/*
** EPITECH PROJECT, 2024
** myconnexion_link.c
** File description:
** link a new connexion to a list
*/

#include "myconnexion.h"

int
myconnexion_link(myconnexion_t **list, myconnexion_t *new)
{
    if (list == NULL) {
        fprintf(stderr, "Error:\tNULL ptr to connexion list.\n");
        return -1;
    }
    if (new == NULL) {
        fprintf(stderr, "Error:\tNew connexion is a NULL ptr\n");
        return -1;
    }
    new->next = *list;
    *list = new;
    return 0;
}
