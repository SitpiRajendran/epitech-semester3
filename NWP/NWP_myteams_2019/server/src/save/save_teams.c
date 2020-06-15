/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** save_teams
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "definitions.h"

void save_team(int fd, team_t *team)
{
    linked_list_t *cursor = team->sub_users;
    user_t *user;
    char team_id[37];
    char user_id[37];

    uuid_unparse(team->uuid, team_id);
    dprintf(fd, "TEAM %s %ld \"%s\" \"%s\" ",
    team_id, team->create_time, team->name, team->description);
    while (cursor) {
        user = cursor->obj;
        uuid_unparse(user->uuid, user_id);
        write(fd, user_id, 36);
        write(fd, " ", 1);
        cursor = cursor->next;
    }
    write(fd, "\n", 1);
}

void save_teams(int fd, team_t *teams)
{
    team_t *cursor = teams;

    while (cursor) {
        save_team(fd, cursor);
        cursor = cursor->next;
    }
}
