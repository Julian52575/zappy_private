/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** Removes a connexion from the list
*/

#include "../includes/myconnexion.h"

void
myconnexion_remove_from_list(myconnexion_t **list, myconnexion_t *tmp)
{
    myconnexion_t *prev_to_tmp = *list;
    myconnexion_t *next_to_tmp = tmp->next;

    if (*list == tmp) {
        *list = tmp->next;
        myconnexion_destroy(tmp);
        return;
    }
    while (prev_to_tmp->next != tmp) {
        prev_to_tmp = prev_to_tmp->next;
    }
    prev_to_tmp->next = next_to_tmp;
    myconnexion_destroy(tmp);
}
