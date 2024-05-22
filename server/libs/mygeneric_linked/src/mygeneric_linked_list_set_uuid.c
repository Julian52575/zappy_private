/*
** EPITECH PROJECT, 2024
** gen linked
** File description:
** set node uuid to passed parameter or generate a new one if 0 is passed
*/

#include "../includes/mygeneric_linked_list.h"

void
mygeneric_linked_list_set_uuid(mygeneric_linked_list_t *node, uuid_t uuid)
{
    if (uuid == 0) {
        uuid_generate(node->uuid);
        return;
    }
    for (int i = 0; i < 16; i++)
        node->uuid[i] = uuid[i];
}
