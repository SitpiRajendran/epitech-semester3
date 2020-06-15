/*
** EPITECH PROJECT, 2020
** NWP_mychannels_2019
** File description:
** infochan_cmd
*/

#include <stdio.h>
#include "commands.h"
#include "my_channel.h"

static void send_chan_infos(int socket, channel_t *channel)
{
    char channel_id[37];

    uuid_unparse(channel->uuid, channel_id);
    dprintf(socket, "INFOCHANOK %s\n\"%s\"\n\"%s\"\r\n",
    channel_id, channel->name, channel->description);
}

int infochan_cmd(tcp_client_t *client, server_t *server, char **message)
{
    channel_t *channel;

    if (message_args_nbr(message) != 2) {
        return (ERR_CMD);
    }
    if (get_user_from_socket(client->sock, server->users) == NULL) {
        return (ERR_LOGIN);
    }
    channel = get_channel_from_id(message[1], server->channels);
    if (channel == NULL) {
        send_response_with_str(ERR_UKN_CHAN, client->sock, message[1]);
        return (NO_RESPONSE);
    }
    send_chan_infos(client->sock, channel);
    return (NO_RESPONSE);
}
