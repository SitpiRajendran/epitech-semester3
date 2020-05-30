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

bool double_list_del_elem_at_front(double_list_t *front)
{
    double_list_t temp = *front;

    if (temp == NULL)
        return false;
    *front = temp->next;
    return true;
}

bool double_list_del_elem_at_back(double_list_t *front)
{
    double_list_t temp = *front;

    if (temp == NULL || temp->next == NULL)
        return false;

    for (; temp->next->next != NULL; temp = temp->next);
    temp->next = NULL;
    return true;
}

bool double_list_del_elem_at_position(double_list_t *front, unsigned int pos)
{
    double_list_t temp = *front;

    if (temp == NULL || temp->next == NULL)
        return false;
    for (unsigned int count = 1; count < pos; count++)
        temp = temp->next;
    temp->next = temp->next->next;
    return true;
}
