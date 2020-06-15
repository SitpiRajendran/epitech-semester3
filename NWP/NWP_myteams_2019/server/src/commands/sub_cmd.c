/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** sub_cmd
*/

#include "logging_server.h"
#include "commands.h"
#include "user.h"
#include "my_team.h"
#include <stdio.h>

void log_sub(uuid_t user_uuid, uuid_t team_uuid)
{
    char user_id[37];
    char team_id[37];

    uuid_unparse(user_uuid, user_id);
    uuid_unparse(team_uuid, team_id);
    server_event_user_join_a_team(team_id, user_id);
}

int sub_cmd(tcp_client_t *client, server_t *server, char **message)
{
    user_t *user;
    team_t *team;

    if (message_args_nbr(message) != 2)
        return (ERR_CMD);
    user = get_user_from_socket(client->sock, server->users);
    if (user == NULL)
        return (ERR_LOGIN);
    team = get_team_from_id(message[1], server->teams);
    if (team == NULL) {
        send_response_with_str(ERR_UKN_TEAM, client->sock, message[1]);
        return (NO_RESPONSE);
    }
    if (add_subscribed_team(user, team) == -1
        || add_sub_user(team, user) == -1) {
        return (ERR_SERVER);
    }
    log_sub(user->uuid, team->uuid);
    dprintf(user->tcp_client->sock, "SUBOK \"%s\"\r\n", message[1]);
    return (NO_RESPONSE);
}
