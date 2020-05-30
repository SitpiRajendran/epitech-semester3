/*
** EPITECH PROJECT, 2020
** cpp_d02a - ex00
** File description:
** double_list_next.c
*/

#include "double_list.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

bool double_list_add_elem_at_position(double_list_t *front, double elem,
                                        unsigned int pos)
{
    doublelist_node_t *node = malloc(sizeof(doublelist_node_t));
    double_list_t temp = *front;

    if (!node || pos > double_list_get_size(*front))
        return false;
    node->value = elem;

    if (pos == 0) {
        double_list_add_elem_at_front(front, elem);
        return true;
    }
    for (unsigned int count = 1; count < pos; count++)
        temp = temp->next;
    node->next = temp->next;
    temp->next = node;
    return true;
}

double double_list_get_elem_at_front(double_list_t list)
{
    if (list == NULL)
        return 0;
    return (list->value);
}

double double_list_get_elem_at_back(double_list_t list)
{
    double_list_t temp = list;

    if (temp == NULL)
        return 0;

    for (; temp->next != NULL; temp = temp->next);
    return (temp->value);
}

double double_list_get_elem_at_position(double_list_t list,
                                        unsigned int position)
{
    double_list_t temp = list;

    if (temp == NULL)
        return 0;

    for (int count = position; count != 0; count--)
        temp = temp->next;
    return (temp->value);
}

doublelist_node_t *double_list_get_first_node_with_value(double_list_t list,
                                                            double value)
{
    double_list_t temp = list;

    if (temp == NULL)
        return NULL;

    for (; temp->value != value && temp->next != NULL; temp = temp->next);
    if (temp->value == value)
        return temp;
    else
        return NULL;
}