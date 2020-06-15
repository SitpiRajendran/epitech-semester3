/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** get_team
*/

#include "my_team.h"

team_t *get_team_from_uuid(uuid_t uuid, team_t *teams)
{
    team_t *cursor = teams;

    while (cursor) {
        if (uuid_compare(uuid, cursor->uuid) == 0) {
            return (cursor);
        }
        cursor = cursor->next;
    }
    return (NULL);
}

team_t *get_team_from_id(const char *id, team_t *teams)
{
    uuid_t uuid;
    team_t *cursor = teams;

    uuid_parse(id, uuid);
    while (cursor) {
        if (uuid_compare(uuid, cursor->uuid) == 0) {
            return (cursor);
        }
        cursor = cursor->next;
    }
    return (NULL);
}
