/*
** EPITECH PROJECT, 2024
** stp
** File description:
** Send the reply buffer to the connexion
** (must only be called when connexion is ready to receive the packets)
*/

#include "../includes/myconnexion.h"
#include <string.h>
#include <unistd.h>
#include <signal.h>

int
myconnexion_write_reply_buffer(myconnexion_t *connexion)
{
    ssize_t write_ret = 0;
    char tmp = '\0';

    if (connexion->reply_end_of_cmd_index == 0)
        return 0;
    tmp = connexion->reply_buffer[connexion->reply_end_of_cmd_index + 1];
    connexion->reply_buffer[connexion->reply_end_of_cmd_index + 1] = '\n';
    signal(SIGPIPE, SIG_IGN);
    write_ret = write(connexion->fd, connexion->reply_buffer,
        connexion->reply_end_of_cmd_index + 1);
    connexion->reply_buffer[connexion->reply_end_of_cmd_index + 1] = tmp;
    if (write_ret > 0)
        myconnexion_shift_buffer(connexion, CL_BUFFER_REPLY, write_ret);
    return 0;
}
