/*
** EPITECH PROJECT, 2020
** cpp_d03a - ex01
** File description:
** btree_first.c
*/

#include "double_btree.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

static  void  populate_left(double_btree_t  tree)
{
    double_btree_t left_sub_tree = tree ->left;
    double_btree_create_node (&( left_sub_tree ->left), 30);
    double_btree_create_node (&( left_sub_tree ->right), 5);
}

static  void  populate_tree(double_btree_t *tree)
{
    double_btree_create_node(tree , 42.5);
    double_btree_create_node (&((* tree)->right), 100);
    double_btree_create_node (&((* tree)->left), 20);
    populate_left (*tree);
}

static  void  test_size(double_btree_t  tree)
{
    unsigned  int  size = double_btree_get_size(tree);
    unsigned  int  depth = double_btree_get_depth(tree);
    printf("The  tree's size is %u\n", size);
    printf("The  tree's depth  is %u\n", depth);
}

static  void  test_values(double_btree_t  tree)
{
    double  max =   double_btree_get_max_value(tree);
    double  min = double_btree_get_min_value(tree);
    printf("The  tree's values  range  from %f to %f\n", min , max);
}

int  main(void)
{
    double_btree_t  tree = NULL;
    populate_tree (&tree);
    test_size(tree);
    test_values(tree);
    return  (0);
}