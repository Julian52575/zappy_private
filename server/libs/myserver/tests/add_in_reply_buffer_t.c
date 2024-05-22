/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** myconnexion unit test my love (????)
*/

#include "../includes/myserver.h"
#include <dirent.h>
#include <netinet/in.h>
#include <assert.h>
#include <stdbool.h>

static void
tests_basic_string(myconnexion_t *cl, char bad_long[], unsigned long len)
{
    myconnexion_overwrite_first_command(cl, CL_BUFFER_REPLY);
    myconnexion_add_in_reply_buffer(cl, "B", 1, true);
    assert(cl->reply_index == 3);
    assert(cl->reply_end_of_cmd_index == 2);
    myconnexion_add_in_reply_buffer(cl, "onjour", strlen("onjour"), true);
    assert(cl->reply_index == 11);
    assert(cl->reply_end_of_cmd_index == 10);
    myconnexion_add_in_reply_buffer(cl, bad_long, strlen(bad_long), true);
    assert(cl->reply_index == (11 + len + 2));
    assert(cl->reply_end_of_cmd_index == 11 + len + 1);
}

static void
test_struct(void)
{
    struct sockaddr_in s = {0};
    myconnexion_t *cl = myconnexion_init(1, &s, "");
    myconnexion_t *dup = NULL;

    myconnexion_add_in_reply_buffer(cl, cl, sizeof(myconnexion_t), true);
    assert(cl->reply_end_of_cmd_index == sizeof(myconnexion_t) + 1);
    dup = (myconnexion_t *) cl->reply_buffer;
    assert(dup->fd == cl->fd);
    assert(dup->status == cl->status);
    assert(dup->buffer == cl->buffer);
}

int main(void)
{
    struct sockaddr_in s = {0};
    myconnexion_t *cl = myconnexion_init(1, &s, "");
    char bad_long[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\
        aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\
        aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\
        aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\
        aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\
        aaaaaaaaaaaaaaaaaaaa";
    unsigned long len = strlen(bad_long);

    tests_basic_string(cl, bad_long, len);
    test_struct();
}
