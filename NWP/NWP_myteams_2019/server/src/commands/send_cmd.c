/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** send_cmd
*/

#include <stdio.h>
#include "logging_server.h"
#include "my_message.h"
#include "commands.h"

void log_send(uuid_t receiver_uuid, uuid_t sender_uuid, const char *message)
{
    char receiver_id[37];
    char sender_id[37];

    uuid_unparse(receiver_uuid, receiver_id);
    uuid_unparse(sender_uuid, sender_id);
    server_event_private_message_sended(sender_id, receiver_id, message);
}

void notify_receiver(uuid_t receive, uuid_t send, server_t *server, char *msg)
{
    user_t *user = get_user_from_uuid(receive, server->users);
    char sender_id[37];

    if (user == NULL) {
        return;
    }
    uuid_unparse(send, sender_id);
    if (user->is_logged && user->tcp_client) {
        dprintf(user->tcp_client->sock, "MESSAGEFROM %s\n\"%s\"\r\n",
        sender_id, msg);
    }
}

int send_cmd(tcp_client_t *tcp_client, server_t *server, char **message)
{
    message_t *msg;
    user_t *user;
    uuid_t receiver_uuid;

    if (message_args_nbr(message) != 3) {
        return (ERR_CMD);
    }
    user = get_user_from_socket(tcp_client->sock, server->users);
    if (user == NULL) {
        return (ERR_LOGIN);
    }
    if (uuid_parse(message[1], receiver_uuid) == -1) {
        send_response_with_str(ERR_VALIDUSER, tcp_client->sock, message[1]);
        return (NO_RESPONSE);
    }
    msg = create_message(user->uuid, receiver_uuid, message[2]);
    add_message_to_list(msg, &server->messages);
    log_send(receiver_uuid, user->uuid, message[2]);
    notify_receiver(receiver_uuid, user->uuid, server, message[2]);
    return (OK);
}
