/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create_channel
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my_channel.h"
#include "logging_server.h"

channel_t *alloc_channel(void)
{
    channel_t *channel = malloc(sizeof(channel_t));

    if (channel == NULL) {
        printf("Error malloc\n");
        return (NULL);
    }
    return (channel);
}

void add_channel(channel_t **channels, channel_t *channel_to_add)
{
    channel_t *cursor;

    if (*channels == NULL) {
        *channels = channel_to_add;
        return;
    }
    cursor = *channels;
    while (cursor->next) {
        cursor = cursor->next;
    }
    cursor->next = channel_to_add;
}

void log_create_chan(const char *name, uuid_t team_uuid, uuid_t channel_uuid)
{
    char team_id[37];
    char channel_id[37];

    uuid_unparse(team_uuid, team_id);
    uuid_unparse(channel_uuid, channel_id);
    server_event_channel_created(team_id, channel_id, name);
}

channel_t *create_channel(const char *name, const char *desc, uuid_t team_uuid)
{
    channel_t *channel = alloc_channel();

    if (channel == NULL) {
        return (NULL);
    }
    strncpy(channel->name, name, MAX_NAME_LENGTH);
    strncpy(channel->description, desc, MAX_DESCRIPTION_LENGTH);
    uuid_generate_random(channel->uuid);
    uuid_copy(channel->team_uuid, team_uuid);
    channel->next = NULL;
    log_create_chan(name, team_uuid, channel->uuid);
    return (channel);
}
