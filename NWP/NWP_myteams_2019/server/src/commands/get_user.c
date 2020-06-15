/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** get_user
*/

#include <string.h>
#include "commands.h"

user_t *get_user_from_name(const char *username, user_t *users)
{
    user_t *cursor = users;

    while (cursor) {
        if (strcmp(username, cursor->username) == 0) {
            return (cursor);
        }
        cursor = cursor->next;
    }
    return (NULL);
}

user_t *get_user_from_socket(int socket, user_t *users)
{
    user_t *cursor = users;

    while (cursor) {
        if (cursor->tcp_client && cursor->tcp_client->sock == socket) {
            return (cursor);
        }
        cursor = cursor->next;
    }
    return (NULL);
}

user_t *get_user_from_uuid(uuid_t uuid, user_t *users)
{
    user_t *cursor = users;

    while (cursor) {
        if (uuid_compare(uuid, cursor->uuid) == 0) {
            return (cursor);
        }
        cursor = cursor->next;
    }
    return (NULL);
}

user_t *get_user_from_id(const char *id, user_t *users)
{
    user_t *cursor = users;
    uuid_t user_uuid;

    uuid_parse(id, user_uuid);
    while (cursor) {
        if (uuid_compare(user_uuid, cursor->uuid) == 0) {
            return (cursor);
        }
        cursor = cursor->next;
    }
    return (NULL);
}
