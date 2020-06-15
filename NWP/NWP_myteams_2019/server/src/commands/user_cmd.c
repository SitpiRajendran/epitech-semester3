/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user_cmd
*/

#include <stdio.h>
#include <string.h>
#include "logging_server.h"
#include "commands.h"

int user_cmd(tcp_client_t *client, server_t *server, char **message)
{
    char user_id[37];
    user_t *user;

    if (get_user_from_socket(client->sock, server->users) == NULL)
        return (ERR_LOGIN);
    if (message_args_nbr(message) != 2)
        return (ERR_CMD);
    if (strlen(message[1]) != 36) {
        send_response_with_str(ERR_VALIDUSER, client->sock, message[1]);
        return (NO_RESPONSE);
    }
    user = get_user_from_id(message[1], server->users);
    if (user == NULL) {
        send_response_with_str(ERR_VALIDUSER, client->sock, message[1]);
        return (NO_RESPONSE);
    }
    uuid_unparse(user->uuid, user_id);
    dprintf(client->sock, "USEROK %s\n\"%s\"\n%d\r\n",
    user_id, user->username, user->is_logged);
    return (NO_RESPONSE);
}
