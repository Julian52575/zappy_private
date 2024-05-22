/*
** EPITECH PROJECT, 2024
** gen linked
** File description:
** unit tests for handler
*/

#include "../includes/mygeneric_linked_list.h"
#include <limits.h>
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <uuid/uuid.h>

static void
tests_errors(mygeneric_linked_list_handler_t *handle)
{
    assert(mygeneric_linked_list_handler_find(handle, LONG_MAX)
        == NULL);
}

static void
add_element(mygeneric_linked_list_handler_t *handle, div_t *data, div_t *osef)
{
    mygeneric_linked_list_t *node = NULL;
    div_t *div = NULL;

    mygeneric_linked_list_handler_add_node(handle,
        data, 512, 0);
    for (int i = 0; i < 99; i++) {
        mygeneric_linked_list_handler_add_node(handle,
            osef, i, 0);
        assert(handle->head->id == i);
    }
    assert(handle->element == 100);
    assert(handle->head->id == 98);
    node = mygeneric_linked_list_handler_find(handle, 512);
    assert(node != NULL);
    div = node->data;
    assert(div != NULL);
    assert(div->quot == data->quot);
}

static void
remove_element(mygeneric_linked_list_handler_t *handle)
{
    size_t elem = handle->element;

    mygeneric_linked_list_handler_remove_node(handle,
        512, true, false);
    assert(handle->head->id == 98);
    assert(handle->element == elem - 1);
    elem = handle->element;
    for (size_t i = 0; i < elem; i++) {
        mygeneric_linked_list_handler_remove_node(handle,
            i, true, false);
        assert(handle->element == (elem - (i + 1)));
    }
    assert(handle->element == 0);
    assert(handle->head == NULL);
}

static void
remove_element_front(mygeneric_linked_list_handler_t *handle)
{
    size_t elem = handle->element;

    mygeneric_linked_list_handler_remove_node(handle,
        512, true, true);
    assert(handle->element == elem - 1);
    assert(handle->element == elem - 1);
    elem = handle->element;
    for (size_t i = 0; i <= elem; i++) {
        mygeneric_linked_list_handler_remove_node(handle,
            ((long) elem - i), true, false);
    }
    assert(handle->element == 0);
    assert(handle->head == NULL);
}

static void
test_uuid_remove(void)
{
    mygeneric_linked_list_handler_t *handle =
        mygeneric_linked_list_handler_init();
    uuid_t uuid = {0};
    uuid_t save = {0};

    uuid_generate(uuid);
    uuid_copy(save, uuid);
    mygeneric_linked_list_handler_add_node(handle, NULL, 42, uuid);
    uuid_generate(uuid);
    mygeneric_linked_list_handler_add_node(handle, NULL, 1, uuid);
    uuid_generate(uuid);
    mygeneric_linked_list_handler_add_node(handle, NULL, 2, uuid);
    uuid_generate(uuid);
    mygeneric_linked_list_handler_remove_node_uuid(handle, save,
        true, false);
    assert(mygeneric_linked_list_handler_find_uuid(handle, save) == 0);
    mygeneric_linked_list_handler_destroy(handle,
        true, false);
}

static void
test_uuid(void)
{
    mygeneric_linked_list_handler_t *handle =
        mygeneric_linked_list_handler_init();
    uuid_t uuid = {0};
    uuid_t save = {0};
    mygeneric_linked_list_t *uuid_yes = NULL;

    uuid_generate(uuid);
    mygeneric_linked_list_handler_add_node(handle, NULL, 42, uuid);
    for (int i = 0; i < 15; i++) {
        assert(uuid[i] == handle->head->uuid[i]);
    }
    uuid_copy(save, uuid);
    uuid_generate(uuid);
    mygeneric_linked_list_handler_add_node(handle, NULL, 1, uuid);
    uuid_generate(uuid);
    mygeneric_linked_list_handler_add_node(handle, NULL, 2, uuid);
    uuid_yes = mygeneric_linked_list_handler_find_uuid(handle, save);
    assert(uuid_compare(uuid_yes->uuid, save) == 0);
    assert(uuid_yes->id == 42);
    mygeneric_linked_list_handler_destroy(handle,
        true, false);
}

int main(void)
{
    div_t *data = malloc(sizeof(div_t));
    div_t *osef = malloc(sizeof(div_t));
    mygeneric_linked_list_handler_t *handle =
        mygeneric_linked_list_handler_init();

    assert(handle != NULL);
    data->quot = 42;
    add_element(handle, data, osef);
    tests_errors(handle);
    remove_element(handle);
    add_element(handle, data, osef);
    remove_element_front(handle);
    test_uuid();
    test_uuid_remove();
    mygeneric_linked_list_handler_destroy(handle,
        true, false);
    return 0;
}
