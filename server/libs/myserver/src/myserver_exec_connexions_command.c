/*
** EPITECH PROJECT, 2024
** ftp lib
** File description:
** parse / run ALL the connexion's command from their buffers
*/

#include "../includes/myserver.h"
#include <time.h>

static void
display_cmd_return_value(myconnexion_t *connexion,
    int return_value, char *cmd_dup)
{
    if (return_value == 0)
        return;
    printf("[%s:%d]\tCommand \'%s\' returned non zero value %d.\n",
        connexion->ip, connexion->port, cmd_dup, return_value);
}

static void
run_connexion_cmd(myserver_t *serv, myconnexion_t *connexion)
{
    mybuffer_info_array_t *info = NULL;
    char *cmd_dup = NULL;
    int (*fun) (myserver_t *, myconnexion_t *,
        mybuffer_info_array_t *) = NULL;
    int val = 0;

    info = myconnexion_get_buffer_info_array(connexion, CL_BUFFER_LISTEN,
        " \r\n\r\0");
    if (info == NULL || info->element == 0)
        return;
    cmd_dup = strndup((char *) info->array[0]->ptr, info->array[0]->length);
    fun = myevent_handler_get_function(serv->event_handler, cmd_dup);
    if (fun != NULL) {
        val = fun(serv, connexion, info);
        display_cmd_return_value(connexion, val, cmd_dup);
    }
    mybuffer_info_array_destroy(info);
    free(cmd_dup);
}

void
myserver_exec_connexions_command(myserver_t *serv)
{
    for (myconnexion_t *tmp = serv->connexion_list;
        tmp != NULL; tmp = tmp->next) {
        if (tmp->end_of_cmd_index == 0)
            continue;
        run_connexion_cmd(serv, tmp);
        myconnexion_overwrite_first_command(tmp, CL_BUFFER_LISTEN);
    }
}
