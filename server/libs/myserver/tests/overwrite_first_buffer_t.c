/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** unit tests for both move buffer
*/

#include "../includes/myserver.h"
#include <assert.h>
#include <netinet/in.h>
#include <string.h>
/*
static void
test_reply_buffer(myconnexion_t *cl)
{
    char msg[] = "Hello world.\r\nBob\r\na\r\n\n\r\naaaaaaaaaaaaaaaaaaaaaaaa";
    unsigned int len = strlen(msg);

    memcpy(cl->reply_buffer, msg, len);
    cl->reply_index = len;
    myconnexion_update_end_of_cmd_index(cl, CL_BUFFER_REPLY);
    assert(cl->reply_buffer[0] == 'H');
    assert(cl->reply_buffer[len - 1] == 'a');
    assert(cl->reply_index == len);
    assert(cl->reply_end_of_cmd_index == 13);
    myconnexion_overwrite_first_command(cl, CL_BUFFER_REPLY);
    assert(cl->reply_index == len - 14);
    assert(cl->reply_buffer[0] != '\n');
    assert(cl->reply_buffer[0] == 'B');
    assert(cl->reply_buffer[4] == CL_END_OF_CMD_CHAR2);
    assert(cl->reply_end_of_cmd_index == 4);
    myconnexion_overwrite_first_command(cl, CL_BUFFER_REPLY);
    assert(cl->reply_buffer[0] == 'a');
    assert(cl->reply_end_of_cmd_index == 2);
    myconnexion_overwrite_first_command(cl, CL_BUFFER_REPLY);
    assert(cl->reply_buffer[0] == '\n');
    assert(cl->reply_end_of_cmd_index == 2);
}

int main(void)
{
    struct sockaddr_in s = {0};
    myconnexion_t *cl = myconnexion_init(1, &s, "");
    char msg[] = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '.',
        '\n', '_', '_', CL_END_OF_CMD_CHAR1, CL_END_OF_CMD_CHAR2,
        'B', 'o', 'b', '\0', '\0', CL_END_OF_CMD_CHAR1,
        CL_END_OF_CMD_CHAR1, CL_END_OF_CMD_CHAR2, 'M', 'a', 'm', 'a', 'm', 'i',
        'a', 's', 'p', 'a', 'g', 'h', 'e', 't', 't', 'i', '!', 'N', 'o', 'w',
        'a', 'y', '\n', CL_END_OF_CMD_CHAR1, CL_END_OF_CMD_CHAR2};
    unsigned long len = strlen(msg) + 5 +
        strlen("Mamamiaspaghetti!Noway\n__\0");
    unsigned long first_cmd_len = 17;

    assert(cl != NULL);
    assert(len == 20 + 5 + 25);
    memcpy(cl->buffer, &(msg[0]), len);
    cl->buffer_index = len;
    myconnexion_update_end_of_cmd_index(cl, CL_BUFFER_LISTEN);
    myconnexion_overwrite_first_command(cl, CL_BUFFER_LISTEN);
    assert(cl->buffer[0] != 'h');
    assert(cl->buffer[0] != CL_END_OF_CMD_CHAR1);
    assert(cl->buffer[0] != CL_END_OF_CMD_CHAR2);
    assert(cl->buffer[0] == 'B');
    assert(cl->buffer[1] == 'o');
    assert(cl->buffer[2] == 'b');
    assert(cl->buffer[15] == 's');
    assert(cl->buffer[len] == '\0');
    assert(cl->buffer_index == len - first_cmd_len);
    assert(cl->buffer[cl->end_of_cmd_index] == CL_END_OF_CMD_CHAR2);
    assert(cl->end_of_cmd_index != len - first_cmd_len - 1);
    test_reply_buffer(cl);
    return 0;
}
*/
int main(void)
{
    printf("Deprecated function disabled for coding style\n");
    return 0;
}
