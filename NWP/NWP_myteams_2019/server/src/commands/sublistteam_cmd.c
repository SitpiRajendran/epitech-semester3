/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** sublistteam_cmd
*/

#include <stdio.h>
#include "my_team.h"
#include "commands.h"

void send_sub_users(int socket, team_t *team)
{
    linked_list_t *cursor = team->sub_users;
    user_t *user;
    char user_id[37];

    while (cursor) {
        user = cursor->obj;
        uuid_unparse(user->uuid, user_id);
        dprintf(socket, "USER %s\n\"%s\"\n%d\n",
        user_id, user->username, user->is_logged);
        cursor = cursor->next;
    }
    dprintf(socket, "\r\n");
}

int sublistteam_cmd(tcp_client_t *client, server_t *server, char **message)
{
    team_t *team;
    user_t *user;

    if (message_args_nbr(message) != 2) {
        return (ERR_CMD);
    }
    user = get_user_from_socket(client->sock, server->users);
    if (user == NULL) {
        return (ERR_LOGIN);
    }
    team = get_team_from_id(message[1], server->teams);
    if (!is_in_team(user, team)) {
        return (ERR_NOTSUB);
    }
    if (team == NULL) {
        send_response_with_str(ERR_UKN_TEAM, client->sock, message[1]);
        return (NO_RESPONSE);
    }
    send_sub_users(client->sock, team);
    return (NO_RESPONSE);
}
