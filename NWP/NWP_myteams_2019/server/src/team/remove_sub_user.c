/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** remove_sub_user
*/

#include <stdlib.h>
#include "definitions.h"

void remove_sub_user(team_t *team, user_t *user)
{
    user_t *tmp_user;
    linked_list_t *cursor = team->sub_users;
    linked_list_t *save = team->sub_users;

    if (team->sub_users->next == NULL) {
        free(team->sub_users);
        team->sub_users = NULL;
        return;
    }
    while (cursor) {
        save = cursor;
        cursor = cursor->next;
        tmp_user = cursor->obj;
        if (uuid_compare(tmp_user->uuid, user->uuid) == 0) {
            save->next = cursor->next;
            free(cursor);
            return;
        }
    }
}
