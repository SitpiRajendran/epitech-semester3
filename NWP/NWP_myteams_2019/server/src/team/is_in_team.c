/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** is_in_team
*/

#include "definitions.h"

int is_in_team(user_t *user, team_t *team)
{
    linked_list_t *cursor = team->sub_users;

    while (cursor) {
        if (cursor->obj == user) {
            return (1);
        }
        cursor = cursor->next;
    }
    return (0);
}
