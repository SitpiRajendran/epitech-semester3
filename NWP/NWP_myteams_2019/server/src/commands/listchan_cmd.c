/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** listchan_cmd
*/

#include <stdio.h>
#include "commands.h"

void send_channels(user_t *user, channel_t *channels)
{
    channel_t *cursor = channels;
    char chan_id[37];

    while (cursor) {
        uuid_unparse(cursor->uuid, chan_id);
        if (uuid_compare(user->context_uuid, cursor->team_uuid) == 0) {
            dprintf(user->tcp_client->sock, "LCHAN %s\n\"%s\"\n\"%s\"\r\n",
            chan_id, cursor->name, cursor->description);
        }
        cursor = cursor->next;
    }
}

int listchan_cmd(tcp_client_t *client, server_t *server, char **message)
{
    user_t *user;

    if (message_args_nbr(message) != 1) {
        return (ERR_CMD);
    }
    user = get_user_from_socket(client->sock, server->users);
    if (user == NULL) {
        return (ERR_LOGIN);
    }
    send_channels(user, server->channels);
    return (NO_RESPONSE);
}
