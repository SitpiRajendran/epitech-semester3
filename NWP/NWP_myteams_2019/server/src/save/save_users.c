/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** save_users
*/

#include <stdio.h>
#include <unistd.h>
#include "definitions.h"

void save_user(int fd, user_t *user)
{
    linked_list_t *cursor = user->sub_teams;
    char user_id[37];
    char team_id[37];
    team_t *team;

    uuid_unparse(user->uuid, user_id);
    dprintf(fd, "USER %s \"%s\" ", user_id, user->username);
    while (cursor) {
        team = cursor->obj;
        uuid_unparse(team->uuid, team_id);
        dprintf(fd, "%s ", team_id);
        cursor = cursor->next;
    }
    write(fd, "\n", 1);
}

void save_users(int fd, user_t *users)
{
    user_t *cursor = users;

    while (cursor) {
        save_user(fd, cursor);
        cursor = cursor->next;
    }
}
