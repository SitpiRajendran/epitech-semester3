/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** add_subscribed_team
*/

#include <stdlib.h>
#include "definitions.h"

int add_subscribed_team(user_t *user, team_t *team)
{
    linked_list_t *node = malloc(sizeof(linked_list_t));
    linked_list_t *cursor = user->sub_teams;

    if (node == NULL) {
        return (-1);
    }
    node->obj = team;
    node->next = NULL;
    if (user->sub_teams == NULL) {
        user->sub_teams = node;
        return (0);
    }
    while (cursor->next) {
        cursor = cursor->next;
    }
    cursor->next = node;
    return (0);
}
