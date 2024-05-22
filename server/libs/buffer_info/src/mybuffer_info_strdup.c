/*
** EPITECH PROJECT, 2024
** buffer info
** File description:
** dump a string present in the buffer info
** buffer_info[1] = strdup("\/login\"")
*/
#include "../includes/mybuffer_info.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static char *
mybuffer_info_strdup_quote(mybuffer_info_t *buffer_info)
{
    const char *src = buffer_info->ptr + 1;
    size_t length = buffer_info->length - 2;
    char *dest = malloc(sizeof(char) * (length + 1));
    size_t i = 0;

    if (dest == NULL) {
        perror("Malloc");
        return NULL;
    }
    for (; i < length; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *
mybuffer_info_strdup(mybuffer_info_t *buffer_info)
{
    char *dup = NULL;

    if (buffer_info == NULL)
        return NULL;
    if (buffer_info->length <= 0)
        return NULL;
    if (buffer_info->ptr[0] == '\"')
        return mybuffer_info_strdup_quote(buffer_info);
    dup = malloc(sizeof(char) * (buffer_info->length + 1));
    if (dup == NULL) {
        perror("Malloc");
        return NULL;
    }
    for (size_t i = 0; i < buffer_info->length; i++)
        dup[i] = buffer_info->ptr[i];
    dup[buffer_info->length] = '\0';
    return dup;
}
