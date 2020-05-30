/*
** EPITECH PROJECT, 2020
** malloc2
** File description:
** malloc
*/

#ifndef MALLOC_H_
#define MALLOC_H_

#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct block_s
{
    size_t size;
    bool free;
    void *address;
    struct block_s *next;
} block_t;

static block_t *head = NULL;

void *malloc(size_t size);
void free(void *ptr);


#endif /* !MALLOC_H_ */
