/*
** EPITECH PROJECT, 2024
** myconnexion_is_buffer_full.c
** File description:
** return true if buffer is full
*/

#include "myconnexion.h"

bool
myconnexion_is_buffer_empty(myconnexion_t *cl)
{
    return (cl->buffer_index == 0);
}
