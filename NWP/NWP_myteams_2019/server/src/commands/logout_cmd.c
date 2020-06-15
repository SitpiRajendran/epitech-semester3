/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** logout_cmd
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "logging_server.h"
#include "commands.h"

static void broadcast_message(const char *username, char *id, user_t *users)
{
    int lenght = strlen(username) + 49;
    char *message = malloc(sizeof(char) * lenght);

    if (message == NULL) {
        return;
    }
    sprintf(message, "LOGOUTOK %s\n\"%s\"\r\n", username, id);
    send_message_to_connected_users(message, users);
    free(message);
}

int logout_user(tcp_client_t *client, server_t *server, char **message)
{
    char user_id[37];
    user_t *user;

    if (message_args_nbr(message) != 1) {
        return (ERR_CMD);
    }
    user = get_user_from_socket(client->sock, server->users);
    if (user == NULL) {
        return (ERR_LOGIN);
    }
    uuid_unparse(user->uuid, user_id);
    server_event_user_logged_out(user_id);
    broadcast_message(user->username, user_id, server->users);
    user->tcp_client = NULL;
    user->is_logged = false;
    return (NO_RESPONSE);
}
