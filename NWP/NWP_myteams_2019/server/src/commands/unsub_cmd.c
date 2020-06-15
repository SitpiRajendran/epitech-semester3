/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** unsub_cmd
*/

#include <stdio.h>
#include "my_team.h"
#include "user.h"
#include "commands.h"
#include "logging_server.h"

void log_unsub(uuid_t team_uuid, uuid_t user_uuid)
{
    char team_id[37];
    char user_id[37];

    uuid_unparse(team_uuid, team_id);
    uuid_unparse(user_uuid, user_id);
    server_event_user_leave_a_team(team_id, user_id);
}

int unsub_cmd(tcp_client_t *client, server_t *server, char **message)
{
    user_t *user;
    team_t *team;

    if (message_args_nbr(message) != 2) {
        return (ERR_CMD);
    }
    user = get_user_from_socket(client->sock, server->users);
    if (user == NULL) {
        return (ERR_LOGIN);
    }
    team = get_team_from_id(message[1], server->teams);
    if (team == NULL) {
        send_response_with_str(ERR_UKN_TEAM, client->sock, message[1]);
        return (NO_RESPONSE);
    }
    remove_sub_user(team, user);
    remove_sub_team(team, user);
    log_unsub(team->uuid, user->uuid);
    dprintf(user->tcp_client->sock, "UNSUBOK \"%s\"\r\n", message[1]);
    return (NO_RESPONSE);
}
