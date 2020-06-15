/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** use_cmd
*/

#include <stdio.h>
#include "commands.h"

int set_context(user_t *user, char **message, server_t *server)
{
    if (user->context == NONE) {
        return (set_team(user, message, server));
    } else if (user->context == TEAM) {
        set_channel(user, message, server);
    } else {
        set_thread(user, message, server);
    }
    return (NO_RESPONSE);
}

int use_cmd(tcp_client_t *client, server_t *server, char **message)
{
    user_t *user = get_user_from_socket(client->sock, server->users);
    int args_nbr = message_args_nbr(message);

    if (user == NULL) {
        return (ERR_LOGIN);
    }
    if (args_nbr == 1) {
        user->context = NONE;
        dprintf(client->sock, "USEOK 0\r\n");
        return (NO_RESPONSE);
    }
    return (set_context(user, message, server));
}