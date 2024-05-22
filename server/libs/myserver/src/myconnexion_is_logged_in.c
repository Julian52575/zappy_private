/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** returns true if the connexion is logged in
*/

#include "../includes/myconnexion.h"
#include <stdbool.h>

bool
myconnexion_is_logged_in(myconnexion_t *connexion)
{
    if (connexion->username[0] == '\0')
        return false;
    if (connexion->password[0] == '\0')
        return false;
    return true;
}
