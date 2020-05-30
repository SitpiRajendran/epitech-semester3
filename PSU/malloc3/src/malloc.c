/*
** EPITECH PROJECT, 2020
** malloc2
** File description:
** malloc
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

    for(; temp->next; temp = temp->next);

    temp->next = to_push;
    return;
}

block_t *best_fit(size_t size)
{
    block_t *temp = head;
    block_t *best = NULL;

    while (temp != NULL) {
        temp->size = temp->size;
        if (best == NULL && temp->size >= size) {
            best = temp;
        } else if (best != NULL && temp->size >= size && temp->size < best->size) {
            best = temp;
        }
        temp = temp->next;
    }
    return best;
}

/***************************************************/

block_t *make_firstmalloc(size_t size)
{
    block_t *alloc;
    block_t *notalloc;
    
    long unsigned int page = 2 * getpagesize();

    while (page < (size + sizeof(block_t)))
        page += (2 * getpagesize());
    if ((alloc = sbrk(page)) == (void*)-1)
        return NULL;
    alloc->size = size;
    alloc->free = false;
    alloc->address = (void*)alloc + sizeof(block_t);
    
    notalloc = (void*)(alloc->address + alloc->size);
    alloc->next = notalloc;
    notalloc->size = page - size - sizeof(block_t) - sizeof(block_t);

    notalloc->free = true;
    notalloc->address = (void*)notalloc + sizeof(block_t);
    notalloc->next = NULL;
    return alloc;
}


block_t *addin(size_t size, block_t*where)
{
    block_t *notal;
    size_t t_size;
    if (where == NULL)
         return NULL;

    where->free = false;
    t_size = where->size;
    where->size = size;

    if ((t_size - size) >= (sizeof(block_t) + 2)) {
        notal = (block_t*)(where->address + where->size);
        notal->free = true;
        notal->size = t_size - size - sizeof(block_t);
        notal->address = (void*)notal + sizeof(block_t);
        write(1, "here\n", 6);
        notal->next = where->next;
        where->next = notal;
    }
    return where;
}

/***************************************************/

void view_mem()
{
    block_t *temp = head;

    if (temp == NULL)
        fprintf(stderr, "NOPE %p\n", sbrk(0));
    while (temp) {
        fprintf(stderr,"--------------------------\n %p  - %p  -  %p\nSize: %ld \t Free:%d\n--------------------------\n", (void*)temp, temp->address, (void *)(temp->address +temp->size), temp->size, temp->free);
        temp = temp->next;
    }
    fprintf(stderr,"%ld \n //BLOCKEND//BLOCKEND//BLOCKEND//\n\n", sizeof(block_t));
}

void my_free(void *ptr)
{
    block_t *to_free = head;
    
    if (ptr == NULL)
        return;
    write(1, "free\n", 6);
    for (; to_free && to_free->address != ptr; to_free = to_free->next);

    to_free->free = true;
}

void *my_malloc(size_t size)
{
    block_t *now;

    
    if (size == 0)
        return NULL;
    size = powertwo(size);
    if (head == NULL) {
        head = make_firstmalloc(size);
        if (head == NULL)
            return NULL;
        return head->address;
    }
    if ((now = best_fit(size)) == NULL) {
        now = make_firstmalloc(size);
        pushback(now);
        return (now->address);
    } else{
        addin(size, now);
        return now->address;
    }

}

int main()
{
    char *str = my_malloc(16);
    char *str2 = my_malloc(32);
    view_mem();
    char *str3 = my_malloc(30);
    char *str4 = my_malloc(30);
    view_mem();

/*     my_free(str2);
    view_mem();
    str2 = my_malloc(10);
    view_mem(); */
    return 0;
}