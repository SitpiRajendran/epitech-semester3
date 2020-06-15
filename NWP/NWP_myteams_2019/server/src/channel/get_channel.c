/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** get_channel
*/

#include "my_channel.h"

channel_t *get_channel_from_uuid(uuid_t uuid, channel_t *channels)
{
    channel_t *cursor = channels;

    while (cursor) {
        if (uuid_compare(uuid, cursor->uuid) == 0) {
            return (cursor);
        }
        cursor = cursor->next;
    }
    return (NULL);
}

channel_t *get_channel_from_id(const char *id, channel_t *channels)
{
    uuid_t uuid;
    channel_t *cursor = channels;

    uuid_parse(id, uuid);
    while (cursor) {
        if (uuid_compare(uuid, cursor->uuid) == 0) {
            return (cursor);
        }
        cursor = cursor->next;
    }
    return (NULL);
}
