/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** Clear reply buffer
*/

#include "../includes/myconnexion.h"

void
myconnexion_clear_reply_buffer(myconnexion_t *connexion)
{
    memset(connexion->reply_buffer, '\0', connexion->reply_index + 1);
    connexion->reply_index = 0;
}
