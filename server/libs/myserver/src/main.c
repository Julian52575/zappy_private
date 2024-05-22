/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** main
*/

#include "myftp.h"

//socket
//bind
//fd_set
//select
//accept

int main(int ac, char **av)
{
    myserver_t serv = {0};

    if (ac != 3) {
        fprintf(stderr, "Usage:\t./myftp [port] [path]\n");
        return 84;
    }
    if (myserver_init(&serv, atoi(av[1]), av[2]) == -1)
        return 84;
    myserver_start(&serv);
    loop(&serv);
    myserver_stop(&serv);
    myserver_free_connexion_list(&serv);
    return 0;
}
