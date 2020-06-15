/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** save_chans
*/

#include <stdio.h>
#include "definitions.h"

void save_chan(int fd, channel_t *channel)
{
    char team_id[37];
    char chan_id[37];

    uuid_unparse(channel->team_uuid, team_id);
    uuid_unparse(channel->uuid, chan_id);
    dprintf(fd, "CHAN %s %s \"%s\" \"%s\"\n",
    chan_id, team_id, channel->name, channel->description);
}

void save_chans(int fd, channel_t *channels)
{
    channel_t *cursor = channels;

    while (cursor) {
        save_chan(fd, cursor);
        cursor = cursor->next;
    }
}
