/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** clear connexion buffer
*/

#include "../includes/myconnexion.h"

void
myconnexion_clear_buffer(myconnexion_t *connexion, enum CL_BUFFER_TYPE type)
{
    if (type == CL_BUFFER_REPLY) {
        memset(connexion->reply_buffer,
            '\0', connexion->reply_length);
        connexion->reply_index = 0;
        connexion->reply_end_of_cmd_index = 0;
    } else {
        memset(connexion->buffer, '\0', connexion->buffer_length);
        connexion->buffer_index = 0;
        connexion->end_of_cmd_index = 0;
    }
}
