/*
** EPITECH PROJECT, 2024
** Network lib
** File description:
** set the connexion type
*/
#include "myconnexion.h"

void
myconnexion_set_type(myconnexion_t *con, size_t type)
{
    con->type = type;
}

size_t
myconnexion_get_type(myconnexion_t *con)
{
    return con->type;
}
