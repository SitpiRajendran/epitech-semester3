/*
** EPITECH PROJECT, 2020
** Piscine C++
** File description:
** main
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "double_list.h"

static  void  populate_list(double_list_t *list_head)
{
    double_list_add_elem_at_front(list_head, 1);
    double_list_add_elem_at_back(list_head, 3);
    double_list_add_elem_at_back(list_head, 4);
    double_list_del_elem_at_back(list_head);
}

static  void  test_size(double_list_t  list_head)
{
    printf("There  are %u elements  in the  list\n", double_list_get_size(list_head));
    double_list_dump(list_head);
}

static  void  test_del(double_list_t *list_head)
{
    double_list_add_elem_at_position(list_head, 2 ,1);
    printf("There  are %u elements  in the  list\n", double_list_get_size (* list_head));
    double_list_dump (* list_head);
}

int  main(void)
{
    double_list_t  list_head = NULL;
    populate_list (& list_head);
    test_size(list_head);
    test_del (& list_head);
    return  0;
}