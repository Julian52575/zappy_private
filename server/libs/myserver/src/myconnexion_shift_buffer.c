/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** move buffer to the left by overwriting the 1st command
** (does nothing if no command are found)
*/

#include "../includes/myconnexion.h"
#include <string.h>

static void
myconnexion_shift_buffer_main(unsigned char *buffer_start,
    unsigned int shift, unsigned int size)
{
    unsigned char *after_shift = buffer_start + shift;
    unsigned int nb_after = size - shift;
    unsigned char *end_to_delete = buffer_start + (size - shift);

    memmove(buffer_start, after_shift, nb_after);
    memset(end_to_delete, '\0', shift);
}

void
myconnexion_shift_buffer(myconnexion_t *connexion,
    enum CL_BUFFER_TYPE type, unsigned int shift)
{
    unsigned char *buffer_start = connexion->buffer;
    unsigned int *index_ptr = &(connexion->buffer_index);
    unsigned int size = connexion->buffer_length;

    if (type == CL_BUFFER_REPLY) {
        buffer_start = connexion->reply_buffer;
        index_ptr = &(connexion->reply_index);
        size = connexion->reply_length;
    }
    if (shift == 0)
        return;
    if (shift >= size - 1) {
        myconnexion_clear_buffer(connexion, type);
    } else {
        myconnexion_shift_buffer_main(buffer_start, shift, size);
    }
    *index_ptr -= shift;
    myconnexion_update_end_of_cmd_index(connexion, type);
}
