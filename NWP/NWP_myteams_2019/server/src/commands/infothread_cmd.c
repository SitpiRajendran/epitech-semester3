/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** infothread_cmd
*/

#include <stdio.h>
#include "commands.h"
#include "my_thread.h"

static void send_thread_infos(int socket, thread_t *thread)
{
    char thread_id[37];
    char user_id[37];

    uuid_unparse(thread->uuid, thread_id);
    uuid_unparse(thread->create_user, user_id);
    dprintf(socket, "INFOTHREADOK %s %s %ld\n\"%s\"\n\"%s\"\r\n",
    thread_id, user_id, thread->create_time, thread->title, thread->message);
}

int infothread_cmd(tcp_client_t *client, server_t *server, char **message)
{
    thread_t *thread;

    if (message_args_nbr(message) != 2) {
        return (ERR_CMD);
    }
    if (get_user_from_socket(client->sock, server->users) == NULL) {
        return (ERR_LOGIN);
    }
    thread = get_thread_from_id(message[1], server->threads);
    if (thread == NULL) {
        send_response_with_str(ERR_UKN_THRD, client->sock, message[1]);
        return (NO_RESPONSE);
    }
    send_thread_infos(client->sock, thread);
    return (NO_RESPONSE);
}

