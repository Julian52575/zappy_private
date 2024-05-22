/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** unit test for myconnexion_remove_from_list.c
*/

#include "../includes/myconnexion.h"
#include <assert.h>

int main(void)
{
    struct sockaddr_in s = {0};
    myconnexion_t *list = myconnexion_init(0, &s, "");
    myconnexion_t *first = list;
    myconnexion_t *second = myconnexion_init(0, &s, "");
    myconnexion_t *third = myconnexion_init(0, &s, "");
    myconnexion_t *fourth = myconnexion_init(0, &s, "");

    myconnexion_link(&list, second);
    myconnexion_remove_from_list(&list, second);
    assert(list == first);
    assert(list->next == NULL);
    myconnexion_link(&list, third);
    myconnexion_link(&list, fourth);
    assert(list == fourth);
    assert(list->next == third);
    assert(list->next->next == first);
    assert(list->next->next->next == NULL);
    return 0;
}
