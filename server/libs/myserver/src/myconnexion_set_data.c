/*
** EPITECH PROJECT, 2024
** ftp lib
** File description:
** fill data inside a connexion
*/

#include "../includes/myconnexion.h"

void
myconnexion_set_data(myconnexion_t *connexion, void *data)
{
    connexion->data = data;
}

void *
myconnexion_get_data(myconnexion_t *connexion)
{
    return connexion->data;
}
