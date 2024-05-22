/*
** EPITECH PROJECT, 2024
** my teams
** File description:
** generic linked list header
*/
#pragma once
#include <uuid/uuid.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>

typedef struct mygeneric_linked_list_s {
    struct mygeneric_linked_list_s *next;
    struct mygeneric_linked_list_s *prev;
    long id;
    uuid_t uuid;
    void *data;
} mygeneric_linked_list_t;
//  Init
mygeneric_linked_list_t *
mygeneric_linked_list_init(void *data, long id);

void
mygeneric_linked_list_set_uuid(mygeneric_linked_list_t *node, uuid_t uuid);
//  Link
void
mygeneric_linked_list_link(mygeneric_linked_list_t **list,
    mygeneric_linked_list_t *node);
void
mygeneric_linked_list_delink(mygeneric_linked_list_t **node,
    bool destroy_node);
//  Free
void
mygeneric_linked_list_destroy(mygeneric_linked_list_t *node,
    bool destroy_data);


//  Handler
typedef struct mygeneric_linked_list_handler_s {
    mygeneric_linked_list_t *head;
    size_t element;
} mygeneric_linked_list_handler_t;
//  Init
mygeneric_linked_list_handler_t *
mygeneric_linked_list_handler_init(void);
//  Node management
//add node
int
mygeneric_linked_list_handler_add_node(
    mygeneric_linked_list_handler_t *handle, void *data, long id, uuid_t uuid);
//rm node
void
mygeneric_linked_list_handler_remove_node(
    mygeneric_linked_list_handler_t *handle, long id,
    bool destroy_node, bool destroy_data);
void
mygeneric_linked_list_handler_remove_node_uuid(
    mygeneric_linked_list_handler_t *handle, uuid_t uuid,
    bool destroy_node, bool destroy_data);
//  Utility
//find
mygeneric_linked_list_t *
mygeneric_linked_list_handler_find(mygeneric_linked_list_handler_t *head,
    long id);
mygeneric_linked_list_t *
mygeneric_linked_list_handler_find_uuid(
    mygeneric_linked_list_handler_t *handle, uuid_t uuid);
//dump
void
mygeneric_linked_list_handler_dump(mygeneric_linked_list_handler_t *handle);
//  Free
void
mygeneric_linked_list_handler_destroy(mygeneric_linked_list_handler_t *node,
    bool destroy_node, bool destroy_data);
