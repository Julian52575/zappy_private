/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** find the next end of command index in the connexion's buffer
*/

#include "../includes/myconnexion.h"


static bool
find_end_delimiters(unsigned char *buffer,
    int index, const uint8_t *delimiters, size_t delimiters_length)
{
    for (size_t i = 0; i < delimiters_length; i++) {
        if (buffer[index + i] != delimiters[i])
            return false;
    }
    return true;
}

static void
update_end_cmd_main(myconnexion_t *connexion,
    unsigned char *buffer_start, unsigned int buffer_size, unsigned int *cmd_index_ptr)
{
    for (unsigned int i = 1; i <= buffer_size; i++) {
        if (buffer_size - i < connexion->delimiters_length)
            break;
        if (find_end_delimiters(buffer_start,
            i, connexion->delimiters, connexion->delimiters_length) == false)
            continue;
        *cmd_index_ptr = i;
        return;
    }
    *cmd_index_ptr = 0;
}

void
myconnexion_update_end_of_cmd_index(myconnexion_t *connexion,
    enum CL_BUFFER_TYPE type)
{
    unsigned char *buffer_start = connexion->buffer;
    unsigned int buffer_size = connexion->buffer_length;
    unsigned int *cmd_index_ptr = &(connexion->end_of_cmd_index);

    if (type == CL_BUFFER_REPLY) {
        buffer_start = connexion->reply_buffer;
        buffer_size = connexion->reply_length;
        cmd_index_ptr = &(connexion->reply_end_of_cmd_index);
    }
    update_end_cmd_main(connexion, buffer_start, buffer_size, cmd_index_ptr);
    return;
}
