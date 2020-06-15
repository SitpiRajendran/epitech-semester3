/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** add_sub_user
*/

#include <stdlib.h>
#include "definitions.h"

int add_sub_user(team_t *team, user_t *user)
{
    linked_list_t *cursor = team->sub_users;
    linked_list_t *node = malloc(sizeof(linked_list_t));

    if (node == NULL) {
        return (-1);
    }
    node->obj = user;
    node->next = NULL;
    if (team->sub_users == NULL) {
        team->sub_users = node;
        return (0);
    }
    while (cursor->next) {
        cursor = cursor->next;
    }
    cursor->next = node;
    return (0);
}
