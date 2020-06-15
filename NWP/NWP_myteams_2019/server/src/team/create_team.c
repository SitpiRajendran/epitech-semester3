/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create_team
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my_team.h"
#include "logging_server.h"
#include "commands.h"

team_t *alloc_team(void)
{
    team_t *team = malloc(sizeof(team_t));

    if (team == NULL) {
        printf("Error malloc\n");
        return (NULL);
    }
    team->sub_users = NULL;
    team->next = NULL;
    memset(team->name, 0, MAX_NAME_LENGTH);
    memset(team->description, 0, MAX_DESCRIPTION_LENGTH);
    return (team);
}

void add_team(team_t **teams, team_t *team_to_add)
{
    team_t *cursor = *teams;

    if (*teams == NULL) {
        *teams = team_to_add;
        return;
    }
    while (cursor->next) {
        cursor = cursor->next;
    }
    cursor->next = team_to_add;
}

void log_create_team(const char *name, uuid_t team_uuid, uuid_t user_uuid)
{
    char user_id[37];
    char team_id[37];

    uuid_unparse(user_uuid, user_id);
    uuid_unparse(team_uuid, team_id);
    server_event_team_created(team_id, name, user_id);
}

team_t *create_team(const char *name, const char *description, uuid_t user)
{
    team_t *team = alloc_team();

    if (team == NULL) {
        return (NULL);
    }
    strncpy(team->name, name, MAX_NAME_LENGTH);
    strncpy(team->description, description, MAX_DESCRIPTION_LENGTH);
    uuid_generate_random(team->uuid);
    team->create_time = time(NULL);
    log_create_team(team->name, team->uuid, user);
    return (team);
}
