/*
** EPITECH PROJECT, 2024
** buffer info
** File description:
** strdup a buffer info
*/
#include "../includes/mybuffer_info.h"
#include <assert.h>

static void
test_quote(void)
{
    const char msg[] = "/login \"Bob le Bricoleur\"";
    mybuffer_info_array_t *info = NULL;
    char *dup = NULL;

    info = mybuffer_info_array_init(msg, strlen(msg), " ");
    assert(info != NULL);
    dup = mybuffer_info_strdup(info->array[1]);
    assert(dup[0] != '\"');
    assert(dup[0] == 'B');
    assert(strcmp(dup, "Bob le Bricoleur") == 0);
    free(dup);
    mybuffer_info_array_destroy(info);
}

int main(void)
{
    const char msg[] = "/login Bob le Bricoleur";
    mybuffer_info_array_t *info = NULL;
    char *dup = NULL;

    info = mybuffer_info_array_init(msg, strlen(msg), " ");
    assert(info != NULL);
    dup = mybuffer_info_strdup(info->array[2]);
    assert(dup != NULL);
    assert(dup != info->array[2]->ptr);
    assert(dup[0] == 'l');
    assert(dup[1] == 'e');
    assert(dup[2] == ' ');
    free(dup);
    dup = mybuffer_info_strdup(info->array[3]);
    assert(strcmp(dup, "Bricoleur") == 0);
    test_quote();
    mybuffer_info_array_destroy(info);
    free(dup);
    return 0;
}
