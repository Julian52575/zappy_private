/*
** EPITECH PROJECT, 2024
** ftp lib
** File description:
** unit tests for myconnexion_shift_buffer
*/

#include "../includes/myconnexion.h"
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>


/*
**     072   58    3A    :                           172   122   7A    z
       073   59    3B    ;                           173   123   7B    {
       074   60    3C    <                           174   124   7C    |
       075   61    3D    =                           175   125   7D    }
       076   62    3E    >
*/

static void
test_listen(myconnexion_t *con)
{
    con->buffer[10] = '1';
    con->buffer[20] = '2';
    con->buffer[30] = '3';
    con->buffer[40] = '4';
    con->buffer[50] = '5';
    con->buffer[60] = '6';
    con->buffer[70] = '7';
    con->buffer[80] = '8';
    con->buffer[90] = '9';
    con->buffer[100] = ':';
    con->buffer[110] = ';';
    con->buffer[120] = '<';
    myconnexion_shift_buffer(con, CL_BUFFER_LISTEN, 10);
    for (unsigned int i = 0; i < 12; i++) {
        assert(con->buffer[10 * i] == ('1' + i));
    }
}

static void
test_reply(myconnexion_t *con)
{
    con->reply_buffer[10] = '1';
    con->reply_buffer[20] = '2';
    con->reply_buffer[30] = '3';
    con->reply_buffer[40] = '4';
    con->reply_buffer[50] = '5';
    con->reply_buffer[60] = '6';
    con->reply_buffer[70] = '7';
    con->reply_buffer[80] = '8';
    con->reply_buffer[90] = '9';
    con->reply_buffer[100] = ':';
    con->reply_buffer[110] = ';';
    con->reply_buffer[120] = '<';
    myconnexion_shift_buffer(con, CL_BUFFER_REPLY, 10);
    for (unsigned int i = 0; i < 12; i++) {
        assert(con->reply_buffer[0] == ('1' + i));
        myconnexion_shift_buffer(con, CL_BUFFER_REPLY, 10);
    }
}

static void
test_invalid(myconnexion_t *con)
{
    myconnexion_shift_buffer(con, CL_BUFFER_REPLY, con->reply_length);
    for (unsigned int i = 0; i < con->reply_length; i++)
        assert(con->reply_buffer[i] == '\0');
}

static void
test_indexs(myconnexion_t *con, const unsigned char msg[])
{
    unsigned int index = con->reply_index;
    unsigned int end_cmd_index = con->reply_end_of_cmd_index;
    unsigned int shift = 30;
    unsigned long len = strlen((char *) &(msg[0]));

    myconnexion_shift_buffer(con, CL_BUFFER_REPLY, shift);
    assert(con->reply_buffer[len - shift] == CL_END_OF_CMD_CHAR1);
    assert(con->reply_buffer[len - shift + 1] == CL_END_OF_CMD_CHAR2);
    for (unsigned int i = 0; i < (len - shift); i++)
        assert(con->reply_buffer[i] == msg[i + shift]);
    for (unsigned int i = (len - shift) + 2; i < len; i++)
        assert(con->reply_buffer[i] == '\0');
    assert(con->reply_index == index - shift);
    assert(con->reply_end_of_cmd_index == end_cmd_index - shift);
    myconnexion_shift_buffer(con, CL_BUFFER_REPLY, (len - shift + 2));
    assert(con->reply_index == 0);
    assert(con->reply_end_of_cmd_index == 0);
}

int main(void)
{
    const char msg[] =
        "Bonjour à tous les amis, c\'est David la farge pokemon,\
        on se retrouve pour une nouvelle vidéo en compagnie de miss jirachi\
        coucou ! Aujourd'hui on va ouvrir des boosters pokémon in-cro-yable !\
        edition soleil et lune!";
    struct sockaddr_in s = {0};
    myconnexion_t *con = myconnexion_init(0, &s, "./");

    assert(con != NULL);
    myconnexion_clear_buffer(con, CL_BUFFER_REPLY);
    test_listen(con);
    test_reply(con);
    myconnexion_clear_buffer(con, CL_BUFFER_REPLY);
    myconnexion_add_in_reply_buffer(con, &(msg[0]), strlen(msg), true);
    test_invalid(con);
    myconnexion_clear_buffer(con, CL_BUFFER_REPLY);
    myconnexion_add_in_reply_buffer(con, &(msg[0]), strlen(msg), true);
    test_indexs(con, (const unsigned char *) msg);
    myconnexion_destroy(con);
    return 0;
}
