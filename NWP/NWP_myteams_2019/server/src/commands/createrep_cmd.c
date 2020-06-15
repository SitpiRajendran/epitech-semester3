/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** createrep_cmd
*/

#include <stdio.h>
#include "my_thread.h"
#include "my_reply.h"
#include "commands.h"

static void send_reply_response(int socket, reply_t *reply)
{
    char thread_id[37];
    char user_id[37];

    if (reply == NULL) {
        dprintf(socket, "ERR_SERVER\r\n");
        return;
    }
    uuid_unparse(reply->thread_uuid, thread_id);
    uuid_unparse(reply->sender, user_id);
    dprintf(socket, "REPCREATED %s\n%s\n%ld\n\"%s\"\r\n",
    thread_id, user_id, reply->create_time, reply->body);
}

int createrep_cmd(tcp_client_t *client, server_t *server, char **message)
{
    user_t *user;
    thread_t *thread;
    reply_t *reply;

    if (message_args_nbr(message) != 2) {
        return (ERR_CMD);
    }
    user = get_user_from_socket(client->sock, server->users);
    if (user == NULL) {
        return (ERR_LOGIN);
    }
    thread = get_thread_from_uuid(user->context_uuid, server->threads);
    if (thread == NULL) {
        return (ERR_UKN_THRD);
    }
    reply = create_reply(message[1], user->uuid, thread->uuid);
    add_reply(&server->replys, reply);
    send_reply_response(client->sock, reply);
    return (NO_RESPONSE);
}