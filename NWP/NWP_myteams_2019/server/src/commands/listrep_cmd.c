/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** listrep_cmd
*/

#include <stdio.h>
#include "commands.h"

static void send_replys(user_t *user, reply_t *replys)
{
    reply_t *cursor = replys;
    char thread_id[37];
    char user_id[37];
    const int socket = user->tcp_client->sock;

    while (cursor) {
        uuid_unparse(cursor->thread_uuid, thread_id);
        uuid_unparse(cursor->sender, user_id);
        if (uuid_compare(user->context_uuid, cursor->thread_uuid) == 0) {
            dprintf(socket, "LREPLY %s\n%s\n%ld\n\"%s\"\r\n", thread_id,
            user_id, cursor->create_time, cursor->body);
        }
        cursor = cursor->next;
    }
}

int listreply_cmd(tcp_client_t *client, server_t *server, char **message)
{
    user_t *user;

    if (message_args_nbr(message) != 1) {
        return (ERR_CMD);
    }
    user = get_user_from_socket(client->sock, server->users);
    if (user == NULL) {
        return (ERR_LOGIN);
    }
    send_replys(user, server->replys);
    return (NO_RESPONSE);
}
