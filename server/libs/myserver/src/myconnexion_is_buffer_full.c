/*
** EPITECH PROJECT, 2024
** myconnexion_is_buffer_full.c
** File description:
** return true if buffer is full
*/

#include "myconnexion.h"

bool
myconnexion_is_buffer_full(myconnexion_t *connexion)
{
    return (connexion->buffer_index == (connexion->buffer_length - 1));
}
