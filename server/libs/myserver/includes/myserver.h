/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** header
*/

#pragma once
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>
#include "myevent_handler.h"
#include "myconnexion.h"

/**
 * @defgroup myserver
 * @brief Easily manage your server thanks to this library
*/

/**
 * @ingroup myserver
 * @brief Structure used to run a server.
*/
typedef struct myserver_s {
    /*      Program dependent    */
    bool running;
    int max_fd;

    /*      Set at lunch    */
    int fd;
    int port;
    struct sockaddr_in config;
    fd_set _read;
    fd_set _write;
    myconnexion_t *connexion_list;
    myevent_handler_t *event_handler;
    void *data;

    const uint8_t *default_delimiters;
    size_t delimiters_length;

    const char *welcome_msg;
    size_t welcome_length;
} myserver_t;


/**
 * @ingroup myserver
 * @brief Create a server on the port provided.
 * @return A instance of myserver_t
 * @param default_delimiters delimiting character to be check in client (by default)
 * @param delimiters_length how many characters will be checked from the ptr
*/
myserver_t *
myserver_init(int port, const char *default_delimiters, size_t delimiters_length);

void
myserver_destroy(myserver_t **serv);

/**
 * @ingroup myserver
 * @brief Get a ptr to myconnexion_t from the fd provided.
 * @param serv The instance of myserver_t to look for
 * @param connexion_fd the fd to search for.
 * @return A ptr to the myconnexion_t that uses the fd
*/
myconnexion_t *
myserver_get_connexion_by_fd(myserver_t *serv, int connexion_fd);

/**
 * @ingroup myserver
 * @brief Start the server.
*/
void
myserver_start(myserver_t *serv);

/**
 * @ingroup myserver
 * @brief Stop the server.
*/
void
myserver_stop(myserver_t *serv);

/**
 * @ingroup myserver
 * @brief Free the memory used by the connexion in serv.
 * @param serv the server
*/
void
myserver_free_connexion_list(myserver_t *serv);

/**
 * @ingroup myserver
 * @brief Check for newly connected clients and adds them to the connexion list.
*/
int
myserver_accept_new_connexion(myserver_t *serv);
/**
 * @ingroup myserver
 * @brief Select the writable / readable fd from the connexion list.
*/
int
myserver_select_connexion(myserver_t *serv);
/**
 * @ingroup myserver
 * @brief Read packets sent by clients.
*/
int
myserver_listen_to_connexions(myserver_t *serv);
/**
 * @ingroup myserver
 * @brief Send packet to clients.
*/
int
myserver_reply_to_connexions(myserver_t *serv);
/**
 * @ingroup myserver
 * @brief Add a new connexion to the connexion list.
*/
int
myserver_add_connexion(myserver_t *serv,
    int connexion_fd, struct sockaddr_in *conf);

/*         Manage connexion FDs        */
/**
 * @ingroup myserver
 * @brief Update the highest fd from the connexion list.
*/
void
myserver_update_max_fd(myserver_t *serv);
/**
 * @ingroup myserver
 * @brief Reset the write / read fd_set and adds the connexions' fd.
*/
void
myserver_reload_fd(myserver_t *serv);

void
myserver_debug_fd(myserver_t *serv);


/**
 * @ingroup myserver
 * @brief Check and remove banned clients.
*/
void
myserver_ban_connexions(myserver_t *serv);
/**
 * @ingroup myserver
 * @brief Remove disconnected clients from the list.
*/
void
myserver_disconnect_connexions(myserver_t *serv);

/**
 * @ingroup myserver
 * @brief Execute clients command.
*/
void
myserver_exec_connexions_command(myserver_t *serv);

/**
 * @ingroup myserver
 * @brief Add a message to every connexion's buffer.
 * @param src the packet to copy
 * @param len the number of byte to copy
 * @param addEndCmdChar add the delimiting characters after the packet ?
*/
void
myserver_add_in_all_reply_buffer(myserver_t *server,
    const void *src, size_t len, bool addEndCmdChar);

/**
 * @ingroup myserver
 * @brief Add src (with delimiters) to every connexion of provided type.
 * @param type the type of the connexion (enum compatible)
 * @param src packet to copy
 * @param byte_length length of the packet
*/
void
myserver_add_to_connexion_type_buffer(myserver_t *server, size_t type,
    const void *src, size_t byte_length);

/**
 * @ingroup myserver
 * @brief Set a ptr to some data to be store inside the server.
 * @param data the ptr to be set.
*/
void
myserver_set_data(myserver_t *server, void *data);

/**
 * @ingroup myserver
 * @brief Get the data ptr set.
 * @return the data pointer
*/
void *
myserver_get_data(myserver_t *server);

/**
 * @ingroup myserver
 * @brief Set a message to be sent to every new connexion.
 * @param message the message to be sent
 * @param message_length the length of the message*/
void
myserver_set_welcome_message(myserver_t *serv,
    const void *message, size_t message_length);
