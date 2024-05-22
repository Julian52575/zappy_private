/*
** EPITECH PROJECT, 2024
** ftp lib
** File description:
** dump buffer_info_array to stdout
*/

#include "../includes/mybuffer_info.h"

static void
mybuffer_info_array_dump_small_len(const char *ptr,
    unsigned int len)
{
    printf("\t");
    for (unsigned int i = 0; i < len; i++) {
        printf("_%c", ptr[i]);
    }
    printf("_\n\t");
    for (unsigned int i = 0; i < len; i++) {
        printf("_%02x", ptr[i]);
    }
    printf("_\n\n");
}

static void
mybuffer_info_array_dump_big_len(const char *tmp,
    unsigned int len)
{
    printf("\t_%c_%c_%c_ ..._ %c_%c_%c_\n", tmp[0], tmp[1], tmp[2],
        tmp[len - 3], tmp[len - 2], tmp[len - 1]);
    printf("\t_%02x_%02x_%02x_ ... _%02x_%02x_%02x_\n", tmp[0],
        tmp[1], tmp[2], tmp[len - 2], tmp[len - 1], tmp[len]);
    printf("\t[0]1]2] ... [%u[%u[%u]\n\n", len - 3, len - 2, len - 1);
}

static void
bufferinfo_dump_main(unsigned int i, const char *tmp, unsigned int len,
    bool quote)
{
    printf("%d\tBuffer ", i);
    if (quote == true)
        printf("in-between quote ");
    printf("of length %u at address %p\n", len, tmp);
    if (len < 6) {
        mybuffer_info_array_dump_small_len(tmp, len);
        return;
    }
    mybuffer_info_array_dump_big_len(tmp, len);
}

void
mybuffer_info_array_dump(mybuffer_info_array_t *info)
{
    const char *tmp = NULL;
    unsigned int len = 0;
    bool quote = false;

    if (info == NULL) {
        printf("Null info...\n");
        return;
    }
    printf("DEBUG]\nBuffer_info_array at address %p of %u elements.\n",
        info, info->element);
    for (unsigned int i = 0; i < info->element; i++) {
        tmp = mybuffer_info_array_get_buffer_ptr(info, i);
        len = mybuffer_info_array_get_length(info, i);
        quote = mybuffer_info_array_is_between_quote(info, i);
        bufferinfo_dump_main(i, tmp, len, quote);
    }
    printf("end of dump\n");
}
