/*
** EPITECH PROJECT, 2024
** network lib
** File description:
** add a welcome msg to the server to be sent to every new connexion
*/
#include "myevent_handler.h"
#include "myserver.h"

void
myserver_set_welcome_message(myserver_t *serv,
    const void *message, size_t message_length)
{
    serv->welcome_msg = message;
    serv->welcome_length = message_length;
}
