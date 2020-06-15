/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** message_cmd
*/

#include <stdio.h>
#include "commands.h"

int is_between_users(message_t *message, user_t *user_a, user_t *user_b)
{
    const int case_a1 = uuid_compare(message->sender, user_a->uuid);
    const int case_a2 = uuid_compare(message->receiver, user_b->uuid);
    const int case_b1 = uuid_compare(message->sender, user_b->uuid);
    const int case_b2 = uuid_compare(message->receiver, user_a->uuid);

    if (case_a1 == 0 && case_a2 == 0) {
        return (1);
    } else if (case_b1 == 0 && case_b2 == 0) {
        return (1);
    }
    return (0);
}

void send_messages_between_users(tcp_client_t *client, server_t *server,
    user_t *user_a, user_t *user_b)
{
    message_t *cursor = server->messages;
    char sender_id[37];

    while (cursor) {
        if (is_between_users(cursor, user_a, user_b)) {
            uuid_unparse(cursor->sender, sender_id);
            dprintf(client->sock, "MESSAGEOK %s\n\"%s\"\n%ld\r\n",
            sender_id, cursor->message, cursor->sent_time);
        }
        cursor = cursor->next;
    }
}

int message_cmd(tcp_client_t *client, server_t *server, char **message)
{
    user_t *user_a;
    user_t *user_b;

    if (message_args_nbr(message) != 2) {
        return (ERR_CMD);
    }
    user_a = get_user_from_id(message[1], server->users);
    if (user_a == NULL) {
        send_response_with_str(ERR_VALIDUSER, client->sock, message[1]);
        return (NO_RESPONSE);
    }
    user_b = get_user_from_socket(client->sock, server->users);
    if (user_b == NULL) {
        return (ERR_LOGIN);
    }
    send_messages_between_users(client, server, user_a, user_b);
    return (NO_RESPONSE);
}
