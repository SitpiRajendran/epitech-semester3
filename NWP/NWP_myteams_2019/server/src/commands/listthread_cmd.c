/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** listthread_cmd
*/

#include <stdio.h>
#include "commands.h"

void send_threads(user_t *user, thread_t *threads)
{
    thread_t *cursor = threads;
    char thread_id[37];
    char user_id[37];

    while (cursor) {
        uuid_unparse(cursor->uuid, thread_id);
        uuid_unparse(cursor->create_user, user_id);
        if (uuid_compare(user->context_uuid, cursor->channel_uuid) == 0) {
            dprintf(user->tcp_client->sock,
            "LTHREAD %s %s %ld\n\"%s\"\n\"%s\"\r\n",
            thread_id, user_id, cursor->create_time,
            cursor->title, cursor->message);
        }
        cursor = cursor->next;
    }
}

int listthread_cmd(tcp_client_t *client, server_t *server, char **message)
{
    user_t *user;

    if (message_args_nbr(message) != 1) {
        return (ERR_CMD);
    }
    user = get_user_from_socket(client->sock, server->users);
    if (user == NULL) {
        return (ERR_LOGIN);
    }
    send_threads(user, server->threads);
    return (NO_RESPONSE);
}
