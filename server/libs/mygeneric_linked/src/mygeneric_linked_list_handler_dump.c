/*
** EPITECH PROJECT, 2024
** gen linked
** File description:
** dump all the node in handler
*/

#include "../includes/mygeneric_linked_list.h"

static void
mygeneric_linked_list_handler_dump_edges(
    mygeneric_linked_list_handler_t *handle)
{
    mygeneric_linked_list_t *it = handle->head;
    unsigned int i = 1;

    for (; it != NULL && i <= 3; it = it->next) {
        printf("%d\tNode at address %p of id %ld.\n", i, it, it->id);
        printf("\tassociated data at address %p.\n\n", it->data);
        i++;
    }
    printf("\t...\n\n");
    for (; it != NULL && it->next != NULL; it = it->next) {
        i++;
    }
    printf("%d\tLast node at address %p of id %ld.\n", i, it, it->id);
    printf("\tassociated data at address %p.\n\n", it->data);
}

static void
mygeneric_linked_list_handler_dump_all(
    mygeneric_linked_list_handler_t *handle)
{
    mygeneric_linked_list_t *it = handle->head;
    unsigned int i = 1;

    for (; it != NULL; it = it->next) {
        printf("%d\tNode at address %p of id %ld.\n", i, it, it->id);
        printf("\tassociated data at address %p.\n\n", it->data);
        i++;
    }
}

void
mygeneric_linked_list_handler_dump(mygeneric_linked_list_handler_t *handle)
{
    printf("DEBUG]\nLinked list handler at address %p of %lu elements.\n",
        handle, handle->element);
    if (handle->element == 0)
        printf("\tempty.\n");
    if (handle->element > 0 && handle->element <= 5) {
        mygeneric_linked_list_handler_dump_all(handle);
    } else if (handle->element > 5) {
        mygeneric_linked_list_handler_dump_edges(handle);
    }
    printf("end of dump.\n");
}
