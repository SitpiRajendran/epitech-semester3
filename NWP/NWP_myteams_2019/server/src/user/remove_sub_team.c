/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** remove_subscribed_team
*/

#include <stdlib.h>
#include "definitions.h"

void remove_sub_team(team_t *team, user_t *user)
{
    team_t *tmp_team;
    linked_list_t *cursor = user->sub_teams;
    linked_list_t *save = user->sub_teams;

    if (user->sub_teams->next == NULL) {
        free(user->sub_teams);
        user->sub_teams = NULL;
        return;
    }
    while (cursor) {
        save = cursor;
        cursor = cursor->next;
        tmp_team = cursor->obj;
        if (uuid_compare(tmp_team->uuid, team->uuid) == 0) {
            save->next = cursor->next;
            free(cursor);
            return;
        }
    }
}