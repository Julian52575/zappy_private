/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** main
*/

#include "../includes/myserver.h"
#include <stdlib.h>

static int
init_listen(myserver_t *serv)
{
    if (listen(serv->fd, 0) == -1) {
        perror("Listen:\t");
        return -1;
    }
    return 0;
}

static int
init_bind(myserver_t *serv, int port)
{
    if (port <= 0) {
        fprintf(stderr, "Error:\tinvalid port %i.\n", port);
        return -1;
    }
    serv->config.sin_family = AF_INET;
    serv->config.sin_port = htons(port);
    if (bind(serv->fd, (struct sockaddr *) &(serv->config),
                sizeof(struct sockaddr_in)) == -1) {
        perror("Bind:\t");
        return -1;
    }
    return 0;
}

static int
init_socket(myserver_t *serv)
{
    serv->fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serv->fd == -1) {
        perror("Socket:\t");
        return -1;
    }
    serv->max_fd = serv->fd;
    return 0;
}

static int
init_fdset(myserver_t *serv)
{
    FD_ZERO(&(serv->_write));
    FD_ZERO(&(serv->_read));
    FD_SET(serv->fd, &(serv->_read));
    return 0;
}

static int
myserver_init_handler(myserver_t *serv)
{
    serv->event_handler = myevent_handler_init();
    if (serv->event_handler == NULL) {
        free(serv);
        return -1;
    }
    return 0;
}

myserver_t *
myserver_init(int port, const char *default_delimiters, size_t delimiters_length)
{
    myserver_t *serv = malloc(sizeof(myserver_t));

    if (serv == NULL)
        return NULL;
    memset(serv, '\0', sizeof(myserver_t));
    if (init_socket(serv) == -1)
        return NULL;
    if (init_bind(serv, port) == -1)
        return NULL;
    if (init_listen(serv) == -1)
        return NULL;
    if (init_fdset(serv) == -1)
        return NULL;
    if (myserver_init_handler(serv) == -1)
        return NULL;
    serv->running = false;
    serv->connexion_list = NULL;
    serv->default_delimiters = (const uint8_t *) default_delimiters;
    serv->delimiters_length = delimiters_length;
    return serv;
}
