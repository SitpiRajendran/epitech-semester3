/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** sublist_cmd
*/

#include <stdio.h>
#include "commands.h"

void send_sublist(int socket, user_t *user)
{
    linked_list_t *cursor = user->sub_teams;
    char team_id[37];
    team_t *team;

    while (cursor) {
        team = cursor->obj;
        uuid_unparse(team->uuid, team_id);
        dprintf(socket, "TEAM %s\n\"%s\"\n\"%s\"\n",
        team_id, team->name, team->description);
        cursor = cursor->next;
    }
    dprintf(socket, "\r\n");
}

int sublist_cmd(tcp_client_t *client, server_t *server, char **message)
{
    user_t *user;

    if (message_args_nbr(message) != 1) {
        return (ERR_CMD);
    }
    user = get_user_from_socket(client->sock, server->users);
    if (user == NULL) {
        return (ERR_LOGIN);
    }
    send_sublist(client->sock, user);
    return (NO_RESPONSE);
}
