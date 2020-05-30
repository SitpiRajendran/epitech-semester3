/*
** EPITECH PROJECT, 2020
** malloc2
** File description:
** useful
*/

#include "../include/memory.h"

size_t powertwo(size_t size)
{
    size_t new_size = 2;

    while (new_size < size)
        new_size *= 2;
    return new_size;
}

void pushback(block_t *to_push)
{
    block_t *temp = head;

    for (; temp->next; temp = temp->next);

    temp->next = to_push;
    return;
}

void *calloc(size_t nmemb, size_t size)
{
    if (nmemb == 0 || size == 0 || (nmemb * size) > SIZE_MAX)
        return NULL;
    char *ptr = malloc(nmemb * size);
    memset(ptr, 0, nmemb * size);
    return ptr;
}

void *realloc(void *ptr, size_t size)
{
    void *new;

    if (size == 0) {
        if (ptr)
            free(ptr);
        return NULL;
    }
    new = malloc(size);

    if (ptr == NULL || new == NULL) {
        if (ptr)
            free(ptr);
        return NULL;
    }
    memcpy(new, ptr, size);
    free(ptr);
    return new;
}