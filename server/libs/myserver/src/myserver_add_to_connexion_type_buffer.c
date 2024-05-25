/*
** EPITECH PROJECT, 2024
** Network lib
** File description:
** add src to all connexion of matching type
*/
#include "myserver.h"

void
myserver_add_to_connexion_type_buffer(myserver_t *server, size_t type,
    const void *src, size_t byte_length)
{
    for (myconnexion_t *con = server->connexion_list;
    con != NULL; con = con->next) {
        if (con->type != type)
            continue;
        myconnexion_add_in_reply_buffer(con, src, byte_length, true);
    }
    return;
}
