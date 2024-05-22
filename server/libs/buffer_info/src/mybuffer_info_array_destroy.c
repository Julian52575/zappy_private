/*
** EPITECH PROJECT, 2024
** ftp lib
** File description:
** destroy the buffer_info_array
*/

#include "../includes/mybuffer_info.h"

void
mybuffer_info_array_destroy(mybuffer_info_array_t *info)
{
    for (unsigned int i = 0; i <= info->element - 1; i++) {
        free(info->array[i]);
    }
    free(info->array);
    free(info);
}
