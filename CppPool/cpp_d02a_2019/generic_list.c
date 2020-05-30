/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** generic_list.c
*/

#include "generic_list.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

unsigned int list_get_size(list_t list)
{
    unsigned int counter = 0;

    while (list) {
        list = list->next;
        counter++;
    }

    return counter;
}

bool list_is_empty(list_t list)
{
    if (!list)
        return true;
    else
        return false;
}

void list_dump(list_t list, value_displayer_t val_disp)
{
    while (list) {
        val_disp(list->value);
        list = list->next;
    }
}

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    node_t *node = malloc(sizeof(node_t));

    if (!node)
        return false;
    node->value = elem;
    node->next = *front_ptr;
    *front_ptr = node;
    return true;
}

bool list_add_elem_at_back(list_t *front, void *elem)
{
    list_t node = malloc(sizeof(node_t));
    list_t temp = *front;

    if (!node)
        return false;
    node->value = elem;

    if (*front == NULL) {
        *front = node;
        return true;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = node;
    node->next = NULL;

    return true;
}
