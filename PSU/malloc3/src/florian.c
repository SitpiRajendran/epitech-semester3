/*
** EPITECH PROJECT, 2020
** malloc2
** File description:
** florian
*/

#include "../include/memory.h"

block_t *get_node(block_t *list, void *ptr) {

    block_t *tmp = list;

    if (ptr == NULL)
        return NULL;

    for (;tmp != NULL; tmp = tmp->next) {
        if ((tmp->address = ptr))
            return tmp;
    }
    return NULL;
}

void *calloc(size_t nmemb, size_t size)
{
    if (nmemb == 0 || size == 0 || (nmemb * size) > SIZE_MAX)
        return NULL;
    write(1, "test", 4);
    write(1, "taaa", 4);
    char *ptr = malloc(nmemb * size);
    for (int i = 0; i != (nmemb * size); i++)
        ptr[i] = 0;
    return ptr;
}

void *realloc(void *ptr, size_t size)
{
    block_t *tmp = get_node(head, ptr);
    block_t *other;
    void *other_ptr = malloc(size);

    write(1, "tbbb", 4);
    if ((other_ptr == NULL) || size == 0) {
        free (ptr);
        return NULL;
    }
    other = get_node(head, other_ptr);
    if (other == NULL || tmp == NULL)
        return other_ptr;
    memcpy(other_ptr, ptr, size);
    free(ptr);
    return other_ptr;
}