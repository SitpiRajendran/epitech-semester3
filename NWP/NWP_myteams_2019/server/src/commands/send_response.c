/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** send_response
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "commands.h"
#include "tcp_server.h"

void send_message_to_connected_users(const char *message, user_t *users)
{
    user_t *cursor = users;

    while (cursor) {
        if (cursor->is_logged && cursor->tcp_client) {
            send_message(cursor->tcp_client->sock, message);
        }
        cursor = cursor->next;
    }
}

void send_response(response_e type, int socket)
{
    static const char *responses[11] = {
    "OK", "SUBOK", "UNSUBOK", "ERR_SERVER", "ERR_LOGIN", "ERR_CMD",
    "ERR_VALIDUSER", "ERR_UKN_TEAM", "ERR_UKN_CHAN", "ERR_UKN_THRD",
    "ERR_NOTSUB"};

    if (type != NO_RESPONSE) {
        send_message(socket, responses[type]);
    }
}

void send_response_with_str(response_e type, int socket, const char *str)
{
    static const char *responses[11] = {
    "OK", "SUBOK", "UNSUBOK", "ERR_SERVER", "ERR_LOGIN", "ERR_CMD",
    "ERR_VALIDUSER", "ERR_UKN_TEAM", "ERR_UKN_CHAN", "ERR_UKN_THRD",
    "ERR_NOTSUB"};
    int size = strlen(responses[type]) + strlen(str) + 1;
    char *full_str = malloc(sizeof(char) * (size + 1));

    sprintf(full_str, "%s %s", responses[type], str);
    if (type != NO_RESPONSE) {
        send_message(socket, full_str);
    }
}
