/*
** EPITECH PROJECT, 2024
** ftp lib
** File description:
** unit tests for mybuffer_info
*/

#include "../includes/mybuffer_info.h"
#include <stdbool.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>

static void
test_single_word(void)
{
    const char msg[] = "/login\r\n";
    mybuffer_info_array_t *info = NULL;

    info = mybuffer_info_array_init(msg, 8, " \t\r\n");
    assert(info != NULL);
    assert(info->element == 1);
    assert(info->array[0]->length == 6);
    mybuffer_info_array_destroy(info);
}

static void
test_sep(void)
{
    const char msg[] = "\t \t \t \t \t \t \n A\r\n\0";
    mybuffer_info_array_t *info = NULL;

    info = mybuffer_info_array_init(msg, strlen(msg), "\t A\r\n");
    assert(info == NULL);
}

static void
test_quote_sep(void)
{
    const char msg[] = "/login\t\"\tBob le\tbricoleur\"\r\n";
    mybuffer_info_array_t *info = NULL;

    info = mybuffer_info_array_init(msg, strlen(msg), " \t\r\n");
    assert(info != NULL);
    assert(info->element == 2);
    assert(info->array[0]->quote == false);
    assert(info->array[1]->quote == true);
    assert(strncmp("\"\tBob le\tbricoleur\"", info->array[1]->ptr,
        info->array[1]->length) == 0);
    mybuffer_info_array_destroy(info);
    return;
}

static void
test_single_letter(void)
{
    const char msg[] = "\t \t \t \t \t \t \n A\r\n\0";
    mybuffer_info_array_t *info = NULL;

    info = mybuffer_info_array_init(msg, strlen(msg), " \t\r\n");
    assert(info != NULL);
    assert(strncmp("A", info->array[0]->ptr, info->array[0]->length) == 0);
    mybuffer_info_array_destroy(info);
}

void
test_quote(void)
{
    const char msg[] = "/login\t \t \t \t\"Bob\"\t\n\"\"\0";
    mybuffer_info_array_t *info = NULL;

    info = mybuffer_info_array_init(msg, strlen(msg), " \t\r\n");
    assert(info != NULL);
    assert(info->element == 3);
    assert(info->array[0]->quote == false);
    assert(info->array[1]->quote == true);
    assert(info->array[2]->quote == true);
    assert(strncmp(info->array[0]->ptr, "/login", info->array[0]->length)
        == 0);
    assert(info->array[0]->length == strlen("/login"));
    assert(strncmp(info->array[1]->ptr, "\"Bob\"", info->array[1]->length)
        == 0);
    assert(info->array[1]->length == strlen("\"Bob\""));
    assert(strncmp("\"\"", info->array[2]->ptr, info->array[2]->length)
        == 0);
    mybuffer_info_array_destroy(info);
}

static void
test_zero(void)
{
    const char msg[] = "/login\r\n\0\0\0\0\0\0\0";
    mybuffer_info_array_t *info = NULL;

    info = mybuffer_info_array_init(msg, 15, "\r\n\0");
    assert(info != NULL);
    assert(info->element == 1);
    assert(strncmp("/login", info->array[0]->ptr, info->array[0]->length)
        == 0);
    mybuffer_info_array_destroy(info);
}

int main(void)
{
    test_sep();
    test_zero();
    test_single_letter();
    test_single_word();
    test_quote();
    test_quote_sep();
}
