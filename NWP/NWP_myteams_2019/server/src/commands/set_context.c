/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** set_context
*/

#include <stdio.h>
#include "my_team.h"
#include "my_channel.h"
#include "my_thread.h"
#include "commands.h"

static void respond(int socket, int status, uuid_t uuid)
{
    char id[37];

    uuid_unparse(uuid, id);
    dprintf(socket, "USEOK %d %s\r\n", status, id);
}

void set_thread(user_t *user, char **message, server_t *server)
{
    thread_t *thread;
    const int sock = user->tcp_client->sock;

    thread = get_thread_from_id(message[1], server->threads);
    if (thread == NULL) {
        send_response_with_str(ERR_UKN_THRD, sock, message[1]);
        return;
    }
    user->context = THREAD;
    uuid_copy(user->context_uuid, thread->uuid);
    respond(user->tcp_client->sock, 3, thread->uuid);
}

void set_channel(user_t *user, char **message, server_t *server)
{
    channel_t *channel;
    const int sock = user->tcp_client->sock;

    channel = get_channel_from_id(message[1], server->channels);
    if (channel == NULL) {
        send_response_with_str(ERR_UKN_CHAN, sock, message[1]);
        return;
    }
    user->context = CHANNEL;
    uuid_copy(user->context_uuid, channel->uuid);
    respond(user->tcp_client->sock, 2, channel->uuid);
    if (message_args_nbr(message) > 2) {
        set_thread(user, &message[1], server);
    }
}

response_e set_team(user_t *user, char **message, server_t *server)
{
    team_t *team = get_team_from_id(message[1], server->teams);
    const int sock = user->tcp_client->sock;

    if (team == NULL) {
        send_response_with_str(ERR_UKN_TEAM, sock, message[1]);
        return (NO_RESPONSE);
    }
    if (!is_in_team(user, team)) {
        return (ERR_NOTSUB);
    }
    user->context = TEAM;
    uuid_copy(user->context_uuid, team->uuid);
    respond(user->tcp_client->sock, 1, team->uuid);
    if (message_args_nbr(message) > 2) {
        set_channel(user, &message[1], server);
    }
    return (NO_RESPONSE);
}
