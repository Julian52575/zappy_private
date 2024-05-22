/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** dump the connexion's buffer to stdotu
*/

#include "../includes/myconnexion.h"

static void
dump_loop(unsigned char *buffer, unsigned int len,
    unsigned int index, unsigned int cmd_index)
{
    for (unsigned int i = 0; i < len; i++) {
        if (i % 8 == 0)
            printf("\n%d:\n", i);
        printf("%02x", buffer[i]);
        if (i > 0 && i == cmd_index)
            printf("!");
        if (i == index)
            printf(".");
        printf(" ");
    }
    printf("\n");
}

void
myconnexion_dump_buffer(myconnexion_t *connexion, enum CL_BUFFER_TYPE type)
{
    unsigned char *buffer = connexion->buffer;
    unsigned int len = connexion->buffer_length;
    unsigned int index = connexion->buffer_index;
    unsigned int cmd_index = connexion->end_of_cmd_index;

    printf("DUMP]\tconnexion %d's ", connexion->fd);
    if (type == CL_BUFFER_REPLY) {
        buffer = connexion->reply_buffer;
        len = connexion->reply_length;
        index = connexion->reply_index;
        cmd_index = connexion->reply_end_of_cmd_index;
        printf("reply ");
    }
    printf("buffer:\n");
    printf("\tIndex _%d_ | End cmd _%d_",
        index, cmd_index);
    dump_loop(buffer, len, index, cmd_index);
}
