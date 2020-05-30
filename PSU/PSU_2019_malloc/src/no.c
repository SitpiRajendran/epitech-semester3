/*
** EPITECH PROJECT, 2020
** $
** File description:
** no
*/


#include "../include/memory.h"

void view_mem(void)
{
    block_t *temp = head;

    fprintf(stderr, "SBRK(0)  = %p\n", sbrk(0));
    if (temp == NULL)
        fprintf(stderr, "NOPE\n");
    while (temp) {
        fprintf(stderr,"--------------------------\n %p  - %p  -  %p\nSize: %ld \t Free:%d\n--------------------------\n", (void*)temp, temp->address, (void *)(temp->address +temp->size), temp->size, temp->free);
        temp = temp->next;
    }
}
/*
int main (void)
{
    char *str = my_calloc(sizeof(char), 16);
    str = "abcdefghijklmnopqr\n";

    view_mem();
    my_free(str);
    return 0;
} */