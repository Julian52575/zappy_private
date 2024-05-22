/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** move buffer to the left by overwriting the 1st command
** (does nothing if no command are found)
*/

#include "../includes/myconnexion.h"
#include <string.h>

void
myconnexion_overwrite_first_command(myconnexion_t *connexion,
    enum CL_BUFFER_TYPE type)
{
    unsigned int end_cmd_index = connexion->end_of_cmd_index;
    unsigned int length = connexion->buffer_length;

    if (type == CL_BUFFER_REPLY) {
        end_cmd_index = connexion->reply_end_of_cmd_index;
        length = connexion->reply_length;
    }
    if (end_cmd_index == 0)
        return;
    if (end_cmd_index >= length - 1) {
        myconnexion_clear_buffer(connexion, type);
    } else {
        myconnexion_shift_buffer(connexion, type, end_cmd_index + 1);
    }
}
