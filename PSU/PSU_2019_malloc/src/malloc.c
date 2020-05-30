/*
** EPITECH PROJECT, 2020
** malloc2
** File description:
** malloc
*/

#include "../include/memory.h"

block_t *create_head(size_t size)
{
    block_t *mem;
    block_t *fred;
    long unsigned int page = 2 * getpagesize();

    while (page < (size + sizeof(block_t)))
        page += (2 * getpagesize());
    if ((mem = sbrk(page)) == (void *)-1)
        return NULL;
    mem->free = false;
    mem->size = size;
    mem->address = (void*)mem + sizeof(block_t);
    mem->next = NULL;
    if (page >= (size + sizeof(block_t) + sizeof(block_t) + 2)) {
        fred = (block_t*)(mem->address + mem->size);
        mem->next = fred;
        fred->free = true;
        fred->size = page - mem->size - sizeof(block_t) - sizeof(block_t);
        fred->address = (void *)fred + sizeof(block_t);
        fred->next = NULL;
    }
    return mem;
}

block_t *addin(block_t *mem, size_t size)
{
    size_t t_size = mem->size;
    block_t *fred;

    mem->free = false;
    mem->size = size;

    if (t_size >= (size + sizeof(block_t) + 2)) {
        fred = (block_t*)(mem->address + mem->size);
        fred->next = mem->next;
        mem->next = fred;

        fred->free = true;
        fred->size = t_size - mem->size - sizeof(block_t);
        fred->address = (void *)fred + sizeof(block_t);
    }

    return mem;
}

block_t *bestfit(size_t size)
{
    block_t *temp = head;
    block_t *best = NULL;
    for (; temp != NULL; temp = temp->next) {
        if (best == NULL && temp->size >= size && temp->free == true)
            best = temp;
        else if (best && temp->size >= size
        && temp->size < best->size && temp->free)
            best = temp;
    }
    if (best != NULL) {
        best = addin(best, size);
        for (temp = head; temp
        && temp->address != best->address; temp = temp->next);
        if (temp)
            temp = best;
        return best;
    }
    best = create_head(size);
    for (temp = head; temp->next; temp = temp->next);
    temp->next = best;
    return best;
}

void free(void *ptr)
{
    block_t *to_free = head;

    if (ptr == NULL)
        return;
    for (; to_free && to_free->address != ptr; to_free = to_free->next);

    if (to_free)
        to_free->free = true;
}

void *malloc(size_t size)
{
    block_t *mem;

    if (size == 0)
        return NULL;
    size = powertwo(size);

    if (head == NULL) {
        head = create_head(size);
        if (head == NULL)
            return NULL;
        return head->address;
    }
    mem = bestfit(size);
    if (mem == NULL)
        return NULL;
    return mem->address;
}