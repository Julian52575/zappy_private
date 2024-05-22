/*
** EPITECH PROJECT, 2024
** Zappy server
** File description:
** loop
*/
#include "myserver.h"
#include "zappy.h"

static int
loop_reply_listen(myserver_t *serv)
{
    if (myserver_listen_to_connexions(serv) == -84) {
        myserver_stop(serv);
        return -84;
    }
    if (myserver_reply_to_connexions(serv) == -84) {
        myserver_stop(serv);
        return -84;
    }
    return 0;
}

void
loop(myserver_t *server)
{
    while (server->running == true) {
        myserver_reload_fd(server);
        if (myserver_select_connexion(server) == -84) {
            myserver_stop(server);
            break;
        }
        if (myserver_accept_new_connexion(server) == -84) {
            myserver_stop(server);
            break;
        }
        if (loop_reply_listen(server) == -84) {
            myserver_stop(server);
            break;
        }
        myserver_exec_connexions_command(server);
        myserver_disconnect_connexions(server);
        myserver_ban_connexions(server);
    }
}
