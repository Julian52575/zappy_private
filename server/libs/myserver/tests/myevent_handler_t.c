/*
** EPITECH PROJECT, 2024
** ftp lib
** File description:
** unit tests for myevent_handler
*/

#include "../includes/myevent_handler.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int
twentyone_function(void *f, void *s, void *t, void *fo)
{
    return 21;
}

int
fourtytwo_function(void *f, void *s, void *t, void *fo)
{
    return 42;
}

int main(void)
{
    myevent_handler_t *handle = myevent_handler_init();
    int (*function)(void *, void *, void *, void *);

    assert(handle != NULL);
    function = myevent_handler_get_function(handle, "This will fail");
    assert(function == NULL);
    myevent_handler_add_event(handle, "42", fourtytwo_function);
    assert(handle->event_list != NULL);
    function = myevent_handler_get_function(handle, "42");
    assert(function != NULL);
    assert(function(NULL, NULL, NULL, NULL) == 42);
    myevent_handler_add_event(handle, "21", &twentyone_function);
    function = myevent_handler_get_function(handle, "21");
    assert(function != NULL);
    assert(function(NULL, NULL, NULL, NULL) == 21);
    function = myevent_handler_get_function(handle, "This will fail 2");
    assert(function == NULL);
    myevent_handler_destroy(handle);
    return 0;
}
