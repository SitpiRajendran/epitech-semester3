/*
** EPITECH PROJECT, 2018
** cpp_d02a
** File description:
** ex01
*/

#ifndef DOUBLE_BTREE_H_
# define DOUBLE_BTREE_H_

/*
** Types
*/

#include <stdbool.h>

typedef struct doublebtree_node
{
    double                  value;
    struct doublebtree_node *left;
    struct doublebtree_node *right;
}   doublebtree_node_t;

typedef doublebtree_node_t *double_btree_t;

/*
** Functions
*/

/* Informations */

bool            double_btree_is_empty(double_btree_t tree);
unsigned int    double_btree_get_size(double_btree_t tree);
unsigned int    double_btree_get_depth(double_btree_t tree);

/* Modifications */

bool    double_btree_create_node(double_btree_t *root_ptr, double value);
bool    double_btree_delete(double_btree_t *root_ptr);

/* Access */

double  double_btree_get_max_value(double_btree_t tree);
double  double_btree_get_min_value(double_btree_t tree);

#endif /* !DOUBLE_BTREE_H_ */
