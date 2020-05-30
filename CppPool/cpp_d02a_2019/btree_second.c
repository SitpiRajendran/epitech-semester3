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

double double_btree_get_max_value(double_btree_t tree)
{
    double max;
    double lef;
    double rig;

    if (tree == NULL)
        return 0;
    lef = double_btree_get_max_value(tree->left);
    rig = double_btree_get_max_value(tree->right);
    (lef > rig) ? (max = lef): (max = rig);
    (tree->value > max) ? (max = tree->value): (max = max);

    return max;
}

double double_btree_get_min_value(double_btree_t tree)
{
    double min;
    double lef;
    double rig;

    if (tree == NULL)
        return 0;
    lef = double_btree_get_min_value(tree->left);
    rig = double_btree_get_min_value(tree->right);
    if (lef != 0 && rig != 0)
        return ((lef < rig) ? lef: rig);
    if (lef == 0 && rig == 0)
        return tree->value;
    if (lef == 0)
        min = rig;
    else if (rig == 0)
        min = lef;
    (tree->value < min) ? (min = tree->value) : (min = min);

    return min;
}