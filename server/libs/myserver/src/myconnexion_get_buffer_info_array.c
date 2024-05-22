/*
** EPITECH PROJECT, 2024
** ftp lib
** File description:
** get a mybuffer_info_array_t struct associated to the client buffer
** the quotelike is used for error handling unless \0 is passed as parameter
*/

#include "../includes/myconnexion.h"
#include <stdbool.h>
#include <stdlib.h>

mybuffer_info_array_t *
myconnexion_get_buffer_info_array(myconnexion_t *connexion,
    enum CL_BUFFER_TYPE type, const char *separators)
{
    const char *buffer_start = (char *) connexion->buffer;
    unsigned int index = connexion->buffer_index;

    if (type == CL_BUFFER_REPLY) {
        buffer_start = (char *) connexion->reply_buffer;
        index = connexion->reply_index;
    }
    if (index == 0 || separators == NULL)
        return NULL;
    return mybuffer_info_array_init(buffer_start, index, separators);
}
