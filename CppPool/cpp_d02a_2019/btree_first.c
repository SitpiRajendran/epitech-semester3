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

bool double_btree_is_empty(double_btree_t tree)
{
    if (tree == NULL)
        return true;
    return false;
}

unsigned int double_btree_get_size(double_btree_t tree)
{
    unsigned int c = 1;

    if (tree == NULL)
        return 0;
    c += double_btree_get_size(tree->left);
    c += double_btree_get_size(tree->right);
    return c;
}

unsigned int double_btree_get_depth(double_btree_t tree)
{
    int l;
    int r;

    if (tree == NULL)
        return 0;
    l = double_btree_get_depth(tree->left);
    r = double_btree_get_depth(tree->right);
    if (l < r)
        return r + 1;
    else
        return l + 1;
}

bool double_btree_create_node(double_btree_t *root_ptr, double value)
{
    *root_ptr = malloc(sizeof(double_btree_t));

    if (*root_ptr == NULL)
        return false;
    else {
        (*root_ptr)->value = value;
        (*root_ptr)->right = NULL;
        (*root_ptr)->left = NULL;
        return true;
    }
}

bool double_btree_delete(double_btree_t *root_ptr)
{
    if (*root_ptr == NULL)
        return false;
    else
        *root_ptr = NULL;
    return true;
}