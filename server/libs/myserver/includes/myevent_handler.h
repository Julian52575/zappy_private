/*
** EPITECH PROJECT, 2024
** ftp lib
** File description:
** generic struct to handle server\'s command
*/
#pragma once


typedef struct myserver_s myserver_t;
typedef struct myconnexion_s myconnexion_t;
typedef struct mybuffer_info_array_s mybuffer_info_array_t;

/**
 * @ingroup myserver
 * @brief Bind a char *command to a function pointer.
*/
typedef struct myevent_s {
    // The command / key to access the function
    const char *cmd;
    // 4 void * for maximum flexibility
    // an int return status
    int (*fun_ptr)(myserver_t *, myconnexion_t *, mybuffer_info_array_t *);

    struct myevent_s *next;
} myevent_t;

/**
 * @ingroup myserver
 * @brief A list of char * and the corresponding function pointer
*/
typedef struct myevent_handler_s {
    myevent_t *event_list;
} myevent_handler_t;

/**
 * @ingroup myserver
 * @brief Init the event_handler.
*/
myevent_handler_t *
myevent_handler_init(void);
/**
 * @ingroup myserver
 * @brief Free the memory zone used by handle.
*/
void
myevent_handler_destroy(myevent_handler_t *handle);

/**
 * @ingroup myserver
 * @brief Add a new event to the handler.
 * @param handler the handler to update
 * @param cmd the command to be check
 * @param function_ptr the function pointer to be run when name is found by myevent_handler_get_function.
 * Prototype: int (*fun_ptr)(myserver_t *, myconnexion_t *, mybuffer_info_array_t *)
 * @return 0 if okay, -1 if a parameter error happened, -84 if malloc failed
*/
int
myevent_handler_add_event(myevent_handler_t *handler,
    const char *cmd, void *function_ptr);

/**
 * @ingroup myserver
 * @brief Get the function pointer associated to cmd
 * @param cmd the cmd to be check in the list
 * @return a function pointer prototyped by: int (*fun_ptr)(myserver_t *, myconnexion_t *, mybuffer_info_array_t *) or NULL
*/
void *
myevent_handler_get_function(myevent_handler_t *handler, const char *cmd);
