/*
** EPITECH PROJECT, 2024
** ftp lib
** File description:
** getter function for mybuffer_info_array
*/

#include "../includes/mybuffer_info.h"

const char *
mybuffer_info_array_get_buffer_ptr(mybuffer_info_array_t *info,
    unsigned int index)
{
    if (index > info->element)
        return NULL;
    return info->array[index]->ptr;
}

unsigned int
mybuffer_info_array_get_length(mybuffer_info_array_t *info,
    unsigned int index)
{
    if (index > info->element)
        return 0;
    return info->array[index]->length;
}

bool
mybuffer_info_array_is_between_quote(mybuffer_info_array_t *info,
    unsigned int index)
{
    if (index > info->element)
        return 0;
    return info->array[index]->quote;
}
