/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** createthread_cmd
*/

#include <stdio.h>
#include "logging_server.h"
#include "my_team.h"
#include "my_channel.h"
#include "my_thread.h"
#include "commands.h"

team_t *get_team_from_channel(uuid_t channel_uuid, server_t *server)
{
    channel_t *channel = get_channel_from_uuid(channel_uuid, server->channels);
    team_t *team;

    if (channel == NULL) {
        return (NULL);
    }
    team = get_team_from_uuid(channel->team_uuid, server->teams);
    return (team);
}

static void broadcast_message(user_t *user, thread_t *thread, server_t *server)
{
    team_t *team = get_team_from_channel(user->context_uuid, server);
    linked_list_t *cursor = team->sub_users;
    user_t *tmp_user;
    char thread_id[37];
    char user_id[37];

    uuid_unparse(thread->uuid, thread_id);
    uuid_unparse(thread->create_user, user_id);
    while (cursor) {
        tmp_user = cursor->obj;
        if (tmp_user->is_logged) {
            dprintf(tmp_user->tcp_client->sock,
            "THREADCREA %s\n%s\n%ld\n\"%s\"\n\"%s\"\r\n",
            thread_id, user_id, thread->create_time,
            thread->title, thread->message);
        }
        cursor = cursor->next;
    }
}

int check_user(user_t *user)
{
    if (user == NULL) {
        return (ERR_LOGIN);
    }
    if (user->context != CHANNEL) {
        return (ERR_CMD);
    }
    return (OK);
}

int createthread_cmd(tcp_client_t *client, server_t *server, char **message)
{
    user_t *user = get_user_from_socket(client->sock, server->users);
    thread_t *thread;
    int status;

    if (message_args_nbr(message) != 3) {
        return (ERR_CMD);
    }
    status = check_user(user);
    if (status != OK) {
        return (status);
    }
    thread =
        create_thread(message[1], message[2], user->context_uuid, user->uuid);
    if (thread == NULL) {
        return (ERR_SERVER);
    }
    add_thread(&server->threads, thread);
    broadcast_message(user, thread, server);
    return (NO_RESPONSE);
}
