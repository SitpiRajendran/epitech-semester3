/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** generic_list_next.c
*/

#include "generic_list.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

bool list_add_elem_at_position(list_t *front, void *elem, unsigned int pos)
{
    node_t *node = malloc(sizeof(node_t));
    list_t temp = *front;

    if (!node || pos > list_get_size(*front))
        return false;
    node->value = elem;

    if (pos == 0) {
        list_add_elem_at_front(front, elem);
        return true;
    }
    for (unsigned int count = 1; count < pos; count++)
        temp = temp->next;
    node->next = temp->next;
    temp->next = node;
    return true;
}

bool list_del_elem_at_front(list_t *front_ptr)
{
    list_t temp = *front_ptr;

    if (temp == NULL)
        return false;
    *front_ptr = temp->next;
    return true;
}

bool list_del_elem_at_back(list_t *front_ptr)
{
    list_t temp = *front_ptr;

    if (temp == NULL || temp->next == NULL)
        return false;

    for (; temp->next->next != NULL; temp = temp->next);
    temp->next = NULL;
    return true;
}

bool list_del_elem_at_position(list_t *front_ptr, unsigned int position)
{
    list_t temp = *front_ptr;

    if (temp == NULL || temp->next == NULL)
        return false;
    for (unsigned int count = 1; count < position; count++)
        temp = temp->next;
    temp->next = temp->next->next;
    return true;
}

void list_clear(list_t *front_ptr)
{
    list_t tmp = *front_ptr;
    list_t suiv;

    *front_ptr = NULL;
    while (tmp != NULL) {
        suiv = tmp->next;
        free(tmp);
        tmp = suiv;
    }
}