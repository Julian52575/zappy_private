/*
** EPITECH PROJECT, 2024
** gen linked
** File description:
** unit tests
*/
#include "../includes/mygeneric_linked_list.h"
#include <assert.h>
#include <stdlib.h>
#include <uuid/uuid.h>

static mygeneric_linked_list_t *
create_list(void)
{
    div_t *data = malloc(sizeof(div_t));
    div_t *data2 = malloc(sizeof(div_t));
    div_t *data3 = malloc(sizeof(div_t));
    div_t *data4 = malloc(sizeof(div_t));
    mygeneric_linked_list_t *list = mygeneric_linked_list_init(data, 100);
    mygeneric_linked_list_t *node1 = mygeneric_linked_list_init(data2, 1);
    mygeneric_linked_list_t *node2 = mygeneric_linked_list_init(data3, 2);
    mygeneric_linked_list_t *node3 = mygeneric_linked_list_init(data4, 3);

    data->quot = 42;
    mygeneric_linked_list_link(&list, node3);
    mygeneric_linked_list_link(&list, node2);
    mygeneric_linked_list_link(&list, node1);
    assert(list != NULL);
    assert(list->id == 1);
    assert(list->next->id == 2);
    assert(list->next->next->id == 3);
    assert(list->next->next->next->id == 100);
    assert(((div_t *)list->next->next->next->data)->quot == 42);
    return list;
}

static void
test_delink(void)
{
    mygeneric_linked_list_t *list = create_list();

    assert(list->id == 1);
    mygeneric_linked_list_delink(&list, true);
    assert(list->id == 2);
    mygeneric_linked_list_delink(&list, true);
    assert(list->id == 3);
    mygeneric_linked_list_delink(&list, true);
    assert(list->id == 100);
    mygeneric_linked_list_delink(&list, true);
    assert(list == NULL);
}

//node <-> list
//          ^tmp
static void
test_delink_single(void)
{
    mygeneric_linked_list_t *list = mygeneric_linked_list_init(NULL, 100);
    mygeneric_linked_list_t *tmp = list;
    mygeneric_linked_list_t *node =
        mygeneric_linked_list_init(NULL, 2);

    mygeneric_linked_list_link(&list, node);
    assert(node->next == tmp);
    assert(tmp->prev == node);
    assert(list == node);
    mygeneric_linked_list_delink(&list, false);
    assert(list == tmp);
    assert(node->next == NULL);
    assert(node->prev == NULL);
    assert(tmp->prev == NULL);
    assert(tmp->next == NULL);
    assert(node->next == NULL);
    mygeneric_linked_list_delink(&node, true);
    assert(node == NULL);
    mygeneric_linked_list_delink(&tmp, true);
    assert(tmp == NULL);
}

static void
test_prev_link(void)
{
    mygeneric_linked_list_t *list = create_list();
    mygeneric_linked_list_t *last = NULL;

    for (last = list; last != NULL; last = last->next) {
        if (last->id == 100)
            break;
    }
    assert(last != NULL);
    assert(last->id == 100);
    assert(last->prev->id == 3);
    assert(last->prev->prev->id == 2);
    assert(last->prev->prev->prev->id == 1);
    assert(last->prev->prev->prev == list);
}

static void
test_uuid(void)
{
    uuid_t uuid = {0};
    mygeneric_linked_list_t *zlist = mygeneric_linked_list_init(NULL, 1);
    mygeneric_linked_list_t *ulist = mygeneric_linked_list_init(NULL, 2);
    unsigned long ztotal = 0;

    uuid_generate(uuid);
    assert(uuid[0] + uuid[1] + uuid[2] != 0);
    mygeneric_linked_list_set_uuid(zlist, 0);
    mygeneric_linked_list_set_uuid(ulist, uuid);
    for (int i = 0; i < 16; i++) {
        ztotal += zlist->uuid[i];
        assert(ulist->uuid[i] == uuid[i]);
    }
    assert(ztotal != 0);
    mygeneric_linked_list_destroy(zlist, false);
    mygeneric_linked_list_destroy(ulist, false);
}

int main(void)
{
    div_t *data = malloc(sizeof(div_t));
    mygeneric_linked_list_t *list = create_list();

    test_prev_link();
    test_delink();
    test_delink_single();
    test_uuid();
    return 0;
}
