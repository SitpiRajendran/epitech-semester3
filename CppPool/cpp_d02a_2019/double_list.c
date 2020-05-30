/*
** EPITECH PROJECT, 2020
** cpp_d02a - ex00
** File description:
** double_list.c
*/

#include "double_list.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

unsigned int double_list_get_size(double_list_t list)
{
    unsigned int counter = 0;

    while (list) {
        list = list->next;
        counter++;
    }

    return counter;
}

bool double_list_is_empty(double_list_t list)
{
    if (!list)
        return true;
    else
        return false;
}

void double_list_dump(double_list_t list)
{
    while (list) {
        printf("%f\n", list->value);
        list = list->next;
    }
}

bool double_list_add_elem_at_front(double_list_t *front, double elem)
{
    doublelist_node_t *node = malloc(sizeof(doublelist_node_t));

    if (!node)
        return false;
    node->value = elem;
    node->next = *front;
    *front = node;
    return true;
}

bool double_list_add_elem_at_back(double_list_t *front, double elem)
{
    double_list_t node = malloc(sizeof(doublelist_node_t));
    double_list_t temp = *front;

    if (!node)
        return false;
    node->value = elem;

    if (*front == NULL) {
        *front = node;
        return true;
    }
    for (temp = *front; temp->next != NULL; temp = temp->next);
    temp->next = node;
    node->next = NULL;

    return true;
}