/*
** EPITECH PROJECT, 2024
** ftp lib
** File description:
** get a mybuffer_info_array_t struct associated to the client buffer
** the quotelike is used for error handling unless \0 is passed as parameter
*/
#include "../includes/mybuffer_info.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
typedef struct mybuffer_info_s {
    const char *ptr;
    unsigned int length;
} mybuffer_info_t;

typedef struct mybuffer_info_array_s {
    mybuffer_info_t **array;
    unsigned int element;
} mybuffer_info_array_t;
*/
static bool
is_char_in_str(char c, const char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] == c)
            return true;
    }
    if (str[i] == '\0' && c == '\0')
        return true;
    return false;
}

static mybuffer_info_array_t *
mybuffer_info_array_alloc(void)
{
    mybuffer_info_array_t *info = malloc(sizeof(mybuffer_info_array_t));

    if (info == NULL) {
        perror("Malloc");
        return NULL;
    }
    info->array = NULL;
    info->element = 0;
    return info;
}

static unsigned int
get_gap_length(const char *gap_start, const char *end, const char *sep)
{
    unsigned int len = 0;

    for (; (gap_start + len) < end; len++) {
        if (is_char_in_str(gap_start[len], sep) == false)
            break;
    }
    return len;
}

static unsigned int
get_section_length(const char *sec_start, const char *end, const char *sep)
{
    unsigned int len = 0;

    for (; (sec_start + len) < end && *sec_start != '\0'; len++) {
        if (is_char_in_str(sec_start[len], sep) == true)
            break;
    }
    return len;
}

static unsigned int
get_quote_length(const char *sec_start, const char *end, bool *full_quote)
{
    unsigned int len = 1;

    *full_quote = false;
    for (; (sec_start + len) < end && *sec_start != '\0'; len++) {
        if (sec_start[len] == '\"') {
            *full_quote = true;
            break;
        }
    }
    return len + 1;
}

static void
add_elem(mybuffer_info_array_t *info,
    const char *current, unsigned int length, bool quote)
{
    info->array = realloc(info->array,
        sizeof(mybuffer_info_t *) * (info->element + 1));
    info->array[info->element] = malloc(sizeof(mybuffer_info_t));
    info->array[info->element]->ptr = current;
    info->array[info->element]->length = length;
    info->array[info->element]->quote = quote;
    info->element += 1;
}

static mybuffer_info_array_t *
myconnexion_build_buffer_info_array(const char *buffer_start,
    const char *end, const char *sep)
{
    const char *parser = buffer_start;
    unsigned int combined_length = 0;
    unsigned int current_section_length = 0;
    unsigned int current_gap_length = 0;
    bool quote = false;
    mybuffer_info_array_t *info = mybuffer_info_array_alloc();

    if (info == NULL)
        return NULL;
    while (parser < end) {
        quote = false;
        if (*parser == '\"')
            current_section_length = get_quote_length(parser, end, &quote);
        else
            current_section_length = get_section_length(parser, end, sep);
        add_elem(info, parser, current_section_length, quote);
        parser += current_section_length;
        parser += get_gap_length(parser, end, sep);
    }
    return info;
}

mybuffer_info_array_t *
mybuffer_info_array_init(const char *buffer, unsigned int length,
    const char *separators)
{
    unsigned int gap_length = 0;
    const char *buffer_start = buffer;
    const char *end = buffer_start + length;
    unsigned int index = length;

    if (length == 0 || separators == NULL)
        return NULL;
    gap_length = get_gap_length(buffer_start, end, separators);
    if (gap_length > 0) {
        if (gap_length >= length)
            return NULL;
        buffer_start += gap_length;
    }
    return myconnexion_build_buffer_info_array(buffer_start,
        end, separators);
}
