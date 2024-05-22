/*
** EPITECH PROJECT, 2024
** myconnexion_update_connexion_buffer.c
** File description:
** updates the connexion buffer by reading its fd
** updates the index and the end_of_cmd_index as well
*/

#include "../includes/myconnexion.h"
#include <stdbool.h>
#include <unistd.h>
//"USER azertynnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn nnnnnnnnnnnn\t\n"
//let's say it cuts after the arrow                        ↑.

static bool
myconnexion_reallocate_listen_buffer(myconnexion_t *connexion)
{
    unsigned int max_len = CL_DEFAULT_BUFFER_LENGTH * CL_MAX_REALLOCATION;
    const char msg[] = "Get out\n";

    if (connexion->buffer_length >= max_len) {
        fprintf(stderr, "I've had enough, get out %s.\n", connexion->ip);
        myconnexion_add_in_reply_buffer(connexion,
            (void *) &(msg[0]), strlen(msg), true);
        connexion->status = CL_BANNED;
        return false;
    }
    return true;
}

int
myconnexion_read_packets(myconnexion_t *connexion)
{
    ssize_t ret = 0;
    bool ban = false;

    if (myconnexion_is_buffer_full(connexion) == true) {
        if (connexion->end_of_cmd_index == 0) {
            ban = myconnexion_reallocate_listen_buffer(connexion);
        }
    }
    if (ban == true)
        return -1;
    ret = read(connexion->fd, connexion->buffer,
        connexion->buffer_length - connexion->buffer_index);
    connexion->buffer_index += ret;
    myconnexion_update_end_of_cmd_index(connexion, CL_BUFFER_LISTEN);
    return ret;
}
