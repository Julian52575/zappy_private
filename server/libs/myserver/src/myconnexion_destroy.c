/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** free the memory allocated for the connexion
*/

#include "../includes/myconnexion.h"

void
myconnexion_destroy(myconnexion_t *connexion)
{
    if (connexion->fd > 0) {
        close(connexion->fd);
    }
    if (connexion->buffer != NULL)
        free(connexion->buffer);
    if (connexion->reply_buffer != NULL)
        free(connexion->reply_buffer);
    if (connexion->username != NULL)
        free(connexion->username);
    if (connexion->password != NULL)
        free(connexion->password);
    free(connexion);
}
