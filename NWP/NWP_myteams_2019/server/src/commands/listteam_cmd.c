/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** listteam_cmd
*/

#include <stdio.h>
#include "commands.h"

static void send_teams(int socket, team_t *teams)
{
    team_t *cursor = teams;
    char team_id[37];

    while (cursor) {
        uuid_unparse(cursor->uuid, team_id);
        dprintf(socket, "LTEAM %s\n\"%s\"\n\"%s\"\r\n",
        team_id, cursor->name, cursor->description);
        cursor = cursor->next;
    }
}

int listteam_cmd(tcp_client_t *client, server_t *server, char **message)
{
    user_t *user;

    if (message_args_nbr(message) != 1) {
        return (ERR_CMD);
    }
    user = get_user_from_socket(client->sock, server->users);
    if (user == NULL) {
        return (ERR_LOGIN);
    }
    send_teams(client->sock, server->teams);
    return (NO_RESPONSE);
}
