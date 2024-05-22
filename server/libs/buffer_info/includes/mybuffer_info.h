/*
** EPITECH PROJECT, 2024
** ftp lib
** File description:
** struct containing info about the user's reply buffer
** such as the start of the Xth argument and it's length
** essentially, str_to_word_array without reallocating the WHOLE damn buffer
*/
#pragma once
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**
 * @defgroup libmybuffer_info
 * @brief Easily separate the packets from your buffer
*/
/**
 * @ingroup libmybuffer_info
 * @brief Infos about a section of a buffer.
 */
typedef struct mybuffer_info_s {
    const char *ptr;
    unsigned int length;
    bool quote;
} mybuffer_info_t;

/**
 * @ingroup libmybuffer_info
 * @brief strdup the section contained in the buffer_info_t struct.
*/
char *
mybuffer_info_strdup(mybuffer_info_t *buffer_info);


/**
 * @ingroup libmybuffer_info
 * @brief A structure that holds a buffer_info_t array created from a splitted buffer.
 * Each buffer_info_t holds a ptr to the start of the section, the section length.
*/
typedef struct mybuffer_info_array_s {
    mybuffer_info_t **array;
    unsigned int element;
} mybuffer_info_array_t;

/**
 * @ingroup libmybuffer_info
 * @brief Init a buffer_info_array with the provided settings.
 * @param buffer The char * buffer to analyse. !Will not be modified
 * @param length How many characters will be included
 * @param delimiters Which characters count as a delimiter (only check one of the list, not all)
*/
mybuffer_info_array_t *
mybuffer_info_array_init(const char *buffer, unsigned int length,
    const char *delimiters);

/**
 * @ingroup libmybuffer_info
 * @brief Get a pointer to the start of the _index_th section.
 * @param info The buffer_info_array_t struct
 * @param index The section you want the pointer from
 */
const char *
mybuffer_info_array_get_buffer_ptr(mybuffer_info_array_t *info,
    unsigned int index);

/**
 * @ingroup libmybuffer_info
 * @brief Get the length of the _index_th section.
 * @param info The buffer_info_array_t struct
 * @param index The section you want the length from
 */
unsigned int
mybuffer_info_array_get_length(mybuffer_info_array_t *info,
    unsigned int index);

/**
 * @ingroup libmybuffer_info
 * @brief Get whether or not the _index_th section was between quote.
 * @param info The buffer_info_array_t struct
 * @param index The section you want to know
 */
bool
mybuffer_info_array_is_between_quote(mybuffer_info_array_t *info,
    unsigned int index);

/**
 * @ingroup libmybuffer_info
 * @brief Dump all the section to stdout.
 * @param info The buffer_info_array_t struct
 */
void
mybuffer_info_array_dump(mybuffer_info_array_t *info);

/**
 * @ingroup libmybuffer_info
 * @brief Free the memory used by info.
 * @param info The buffer_info_array_t struct
 */
void
mybuffer_info_array_destroy(mybuffer_info_array_t *info);
