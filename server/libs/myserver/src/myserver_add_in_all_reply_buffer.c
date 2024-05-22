/*
** EPITECH PROJECT, 2024
** ftp lib
** File description:
** add in every client's reply buffer
*/
#include "../includes/myserver.h"

void
myserver_add_in_all_reply_buffer(myserver_t *server,
    const void *src, size_t len, bool addEndCmdChar)
{
    if (src == NULL)
        return;
    for (myconnexion_t *tmp = server->connexion_list;
    tmp != NULL; tmp = tmp->next) {
        myconnexion_add_in_reply_buffer(tmp, src, len, addEndCmdChar);
    }
    return;
}
