/*
** EPITECH PROJECT, 2024
** Zappy server
** File description:
** main
*/
#include "myevent_handler.h"
#include "myserver.h"
#include "zappy.h"

static void
hello_world(void)
{
    printf("Hello world\n");
}

static void
close_server(myserver_t *server,
    myconnexion_t *connexion, mybuffer_info_array_t *info)
{
    printf("Closing server...\n");
    myserver_stop(server);
    mybuffer_info_array_dump(info);
}


static void
add_event_function_to_server(myserver_t *server)
{
    myevent_handler_add_event(server->event_handler,
        ".hello_world", hello_world);
    myevent_handler_add_event(server->event_handler,
        ".stop", close_server);
}

#warning Parse config
int main(int ac, char * const *av)
{
    myserver_t *server = myserver_init(4242, "\n", 1);

    if (ac != 2) {
        printf("%s\n", usage);
        return 84;
    }
    if (server == NULL)
        return 84;
    add_event_function_to_server(server);
    myserver_start(server);
    loop(server);
    myserver_destroy(&server);
    return 0;
}
