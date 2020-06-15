/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** createchan_cmd
*/

#include <stdio.h>
#include "logging_server.h"
#include "my_channel.h"
#include "my_team.h"
#include "commands.h"

static void broadcast_message(channel_t *channel, server_t *server)
{
    team_t *team = get_team_from_uuid(channel->team_uuid, server->teams);
    linked_list_t *cursor = team->sub_users;
    user_t *user;
    char channel_id[37];

    uuid_unparse(channel->uuid, channel_id);
    while (cursor) {
        user = cursor->obj;
        if (user->is_logged) {
            dprintf(user->tcp_client->sock,
            "CHANCREATED %s\n\"%s\"\n\"%s\"\r\n",
            channel_id, channel->name, channel->description);
        }
        cursor = cursor->next;
    }
}

int createchan_cmd(tcp_client_t *client, server_t *server, char **message)
{
    user_t *user = get_user_from_socket(client->sock, server->users);
    channel_t *channel;

    if (message_args_nbr(message) != 3) {
        return (ERR_CMD);
    }
    if (user == NULL) {
        return (ERR_LOGIN);
    }
    if (user->context != TEAM) {
        return (ERR_CMD);
    }
    channel = create_channel(message[1], message[2], user->context_uuid);
    if (channel == NULL) {
        return (ERR_SERVER);
    }
    add_channel(&server->channels, channel);
    broadcast_message(channel, server);
    return (NO_RESPONSE);
}
