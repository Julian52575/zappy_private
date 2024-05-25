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
#include "../../buffer_info/includes/mybuffer_info.h"

#define CL_DEFAULT_BUFFER_LENGTH 2097152 //2 mo
#define CL_MAX_REALLOCATION 5
#define CL_DEFAULT_REPLY_LENGTH 2097152
#define CL_PATH_LENGTH 3200
#define CL_USER_LENGTH 64
#define CL_PSWD_LENGTH 2048

enum CL_BUFFER_TYPE {
    CL_BUFFER_LISTEN,
    CL_BUFFER_REPLY
};

enum CL_STATUS {
    CL_CONNECTED,
    CL_DISCONNECTED,
    CL_BANNED
};


/**
 * @ingroup myserver
 * @brief A structure corresponding to a connection
*/
typedef struct myconnexion_s {
    enum CL_STATUS status;
    int fd;
    char *ip;
    int port;
    struct sockaddr_in config;
    char *username;
    char *password;
    unsigned char *buffer;
    unsigned int buffer_index;
    unsigned int end_of_cmd_index;
    unsigned int buffer_length;

    unsigned char *reply_buffer;
    unsigned int reply_index;
    unsigned int reply_end_of_cmd_index;
    unsigned int reply_length;

    void *data;

    const uint8_t *delimiters;
    size_t delimiters_length;

    size_t type;

    struct myconnexion_s *next;
} myconnexion_t;

/**
 * @ingroup myserver
 * @brief Init a connexion.
 * @param packet_delimtier delimiters between each packets
 * @param delimiter_length how many delimiters are read from packet_delimiter
*/
myconnexion_t *
myconnexion_init(int connexion_fd, struct sockaddr_in *config,
    const uint8_t *packet_delimiter, size_t delimiter_length);
/**
 * @ingroup myserver
 * @brief Link a new connexion to a list.
 * @param list a double pointer to a myconnexion acting as the head of a list
 * @param new the connection to add
 * @return 0 if okay, -1 if parameter error
*/
int
myconnexion_link(myconnexion_t **list, myconnexion_t *new);

/**
 * @ingroup myserver
 * @brief Check if a connexion is logged in.
*/
bool
myconnexion_is_logged_in(myconnexion_t *connexion);

/**
 * @ingroup myserver
 * @brief Remove the first command from a client's buffer.
 * @param type the buffer to be updated
*/
void
myconnexion_overwrite_first_command(myconnexion_t *connexion,
    enum CL_BUFFER_TYPE type);
/**
 * @ingroup myserver
 * @brief Remove X bytes from a client's buffer.
 * @param type the buffer to be updated
 * @param shift the number of byte to be erased
*/
void
myconnexion_shift_buffer(myconnexion_t *connexion,
    enum CL_BUFFER_TYPE type, unsigned int shift);

/**
 * @ingroup myserver
 * @brief Check if the buffer is at full capacity.
*/
bool
myconnexion_is_buffer_full(myconnexion_t *connexion);

/**
 * @ingroup myserver
 * @brief Update the new index of the 1st command to be complete in the buffer.
 * @param type the buffer to be updated
*/
void
myconnexion_update_end_of_cmd_index(myconnexion_t *connexion,
    enum CL_BUFFER_TYPE type);
/**
 * @ingroup myserver
 * @brief Dump a connexion's buffer to stdout.
 * @param type the buffer to be dumped
*/
void
myconnexion_dump_buffer(myconnexion_t *connexion, enum CL_BUFFER_TYPE type);

/**
 * @ingroup myserver
 * @brief Read bytes from the connexion's fd and store it in the connexion's buffer.
*/
int
myconnexion_read_packets(myconnexion_t *cl);
/**
 * @ingroup myserver
 * @brief Reset a connexion's buffer to the \0 byte.
 * @param type the buffer to be updated
*/
void
myconnexion_clear_buffer(myconnexion_t *cl, enum CL_BUFFER_TYPE type);

/**
 * @ingroup myserver
 * @brief Write a connexion's reply buffer to its fd.
*/
int
myconnexion_write_reply_buffer(myconnexion_t *connexion);

/**
 * @ingroup myserver
 * @brief Add data to a connexion's reply buffer to be sent later.
 * @param src the ptr to the data
 * @param byte_length the number of byte to be copied
 * @param addEndCmdChar add the delimiters after the data ?
*/
int
myconnexion_add_in_reply_buffer(myconnexion_t *connexion,
    const void *src, size_t byte_length, bool add_delimiters);

/**
 * @ingroup myserver
 * @brief Get a newly allocated mybuffer_info_array_t from one of the connexion's buffer.
 * @param type the buffer to be analysed
 * @param separators the separating characters
*/
mybuffer_info_array_t *
myconnexion_get_buffer_info_array(myconnexion_t *connexion,
    enum CL_BUFFER_TYPE type, const char *separators);

/**
 * @ingroup myserver
 * @brief Store data to the connexion to be accessed later.
 * @param data the ptr to the data
*/
void
myconnexion_set_data(myconnexion_t *connexion, void *data);

/**
 * @ingroup myserver
 * @brief Get the data stored inside the connexion.
*/
void *
myconnexion_get_data(myconnexion_t *connexion);

void
myconnexion_remove_from_list(myconnexion_t **list, myconnexion_t *tmp);

/**
 * @ingroup myserver
 * @brief Get the type of connexion.
 * @return the type of connexion (enum compatible)
*/
size_t
myconnexion_get_type(myconnexion_t *con);

/**
 * @ingroup myserver
 * @brief Set the connexion type.
 * @param type the type of the connexion (enum compatible)
*/
void
myconnexion_set_type(myconnexion_t *con, size_t type);

/**
 * @ingroup myserver
 * @brief Free the memory zone used by connexion.
*/
void
myconnexion_destroy(myconnexion_t *connexion);
