/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** myserver_loop
*/

#include "../includes/myftp.h"
#warning how to deal with telnet deconecting by closing the terminal ?

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
loop(myserver_t *serv)
{
    while (serv->running == true) {
        myserver_reload_fd(serv);
        if (myserver_select_connexion(serv) == -84) {
            myserver_stop(serv);
            break;
        }
        if (myserver_accept_new_connexion(serv) == -84) {
            myserver_stop(serv);
            break;
        }
        if (loop_reply_listen(serv) == -84) {
            myserver_stop(serv);
            break;
        }
        myserver_disconnect_connexions(serv);
        myserver_ban_connexions(serv);
    }
}
