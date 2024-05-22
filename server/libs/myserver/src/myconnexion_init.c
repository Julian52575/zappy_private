/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** init a new connexion node
*/

#include "../includes/myconnexion.h"
#include <stdlib.h>
#include <string.h>

static int
init_user_buffer(myconnexion_t *new)
{
    new->username = malloc(sizeof(char) * CL_USER_LENGTH);
    if (new->username == NULL) {
        free(new);
        fprintf(stderr, "Malloc:\tAllocation error.\n");
        return -1;
    }
    memset(new->username, '\0', CL_USER_LENGTH);
    new->password = malloc(sizeof(char) * CL_PSWD_LENGTH);
    if (new->password == NULL) {
        free(new->username);
        free(new);
        fprintf(stderr, "Malloc:\tAllocation error.\n");
        return -1;
    }
    memset(new->password, '\0', CL_PSWD_LENGTH);
    return 0;
}

static int
init_socket_buffer(myconnexion_t *new)
{
    new->buffer = malloc(sizeof(char) * CL_DEFAULT_BUFFER_LENGTH);
    if (new->buffer == NULL) {
        free(new);
        fprintf(stderr, "Malloc:\tAllocation error.\n");
        return -1;
    }
    memset(new->buffer, '\0', CL_DEFAULT_BUFFER_LENGTH);
    new->buffer_index = 0;
    new->end_of_cmd_index = 0;
    new->buffer_length = CL_DEFAULT_BUFFER_LENGTH;
    return 0;
}

static int
myconnexion_init_reply(myconnexion_t *cl)
{
    cl->reply_length = CL_DEFAULT_REPLY_LENGTH;
    cl->reply_buffer = malloc(sizeof(char) * cl->reply_length);
    if (cl->reply_buffer == NULL)
        return -1;
    memset(cl->reply_buffer, '\0', cl->reply_length);
    cl->reply_index = 0;
    cl->reply_end_of_cmd_index = 0;
    return 0;
}

static int
myconnexion_call_init_fun(myconnexion_t *new, const uint8_t *packet_delimiter, size_t delimiter_length)
{
    if (packet_delimiter) {
        new->delimiters = packet_delimiter;
        new->delimiters_length = delimiter_length;
    } else {
        new->delimiters = (uint8_t *) "\r\n";
        new->delimiters_length = 2;
    }
    if (init_socket_buffer(new) == -1) {
        free(new);
        return -1;
    }
    if (init_user_buffer(new) == -1) {
        free(new);
        return -1;
    }
    if (myconnexion_init_reply(new) == -1) {
        free(new);
        return -1;
    }
    return 0;
}

myconnexion_t *
myconnexion_init(int connexion_fd,
    struct sockaddr_in *config, const uint8_t *packet_delimiter, size_t delimiter_length)
{
    myconnexion_t *new = malloc(sizeof(myconnexion_t));

    memset(new, '\0', sizeof(myconnexion_t));
    if (new == NULL) {
        fprintf(stderr, "Malloc:\tAllocation error.\n");
        return NULL;
    }
    if (myconnexion_call_init_fun(new, packet_delimiter, delimiter_length) == -1)
        return NULL;
    memcpy(&(new->config), config, sizeof(struct sockaddr_in));
    new->next = NULL;
    new->fd = connexion_fd;
    new->ip = inet_ntoa(new->config.sin_addr);
    new->port = new->config.sin_port;
    new->status = CL_CONNECTED;
    new->data = NULL;
    return new;
}
