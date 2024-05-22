/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** Add a string to the connexion's reply buffer
** (allocate more memory if needed)
*/

#include "../includes/myconnexion.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int
myconnexion_reallocate_reply(myconnexion_t *connexion,
    int left, unsigned int len)
{
    size_t size_needed = 0;

    size_needed = ((len - left) + connexion->reply_length + 2);
    connexion->reply_buffer = reallocarray(connexion->reply_buffer,
        size_needed, sizeof(char));
    if (connexion->reply_buffer == NULL) {
        perror("Reallocarray");
        return -84;
    }
    memset(connexion->reply_buffer + connexion->reply_index, '\0', len);
    connexion->reply_length = size_needed;
    return 0;
}

static void
add_end_cmd_char(myconnexion_t *connexion)
{
    for (size_t i = 0; i < connexion->delimiters_length; i++) {
        connexion->reply_buffer[connexion->reply_index] = connexion->delimiters[i];
        connexion->reply_index += 1;
    }
    connexion->reply_end_of_cmd_index = connexion->reply_index - 1;
}

int
myconnexion_add_in_reply_buffer(myconnexion_t *connexion,
    const void *src, size_t len, bool add_delimiters)
{
    unsigned int left = 0;
    int status = 0;

    if (connexion == NULL)
        return -1;
    len += connexion->delimiters_length;
    left = (connexion->reply_length - connexion->reply_index);
    if (left < len) {
        status = myconnexion_reallocate_reply(connexion, left, len + connexion->delimiters_length);
        if (status < 0)
            return status;
    }
    memcpy(connexion->reply_buffer + connexion->reply_index, src, len);
    connexion->reply_index += len;
    if (add_delimiters == true)
        add_end_cmd_char(connexion);
    return 0;
}
