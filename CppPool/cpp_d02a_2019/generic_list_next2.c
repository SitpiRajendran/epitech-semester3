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

void *list_get_elem_at_front(list_t list)
{
    if (list == NULL)
        return 0;
    return (list->value);
}

void *list_get_elem_at_back(list_t list)
{
    list_t temp = list;

    if (temp == NULL)
        return 0;

    for (; temp->next != NULL; temp = temp->next);
    return (temp->value);
}

void *list_get_elem_at_position(list_t list, unsigned int position)
{
    list_t temp = list;

    if (temp == NULL)
        return 0;

    for (int count = position; count != 0; count--)
        temp = temp->next;
    return (temp->value);
}

node_t *list_get_first_node_with_value(list_t list, void *value,
                                        value_comparator_t val_comp)
{
    list_t tmp = list;

    if (tmp == NULL)
        return NULL;

    for (; val_comp(tmp->value, value) != 0 && tmp->next != NULL;
        tmp = tmp->next);
    if (val_comp(tmp->value, value) == 0)
        return tmp;
    else
        return NULL;
}