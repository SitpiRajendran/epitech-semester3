/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** createteam_cmd
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "commands.h"
#include "my_team.h"
#include "logging_server.h"

static void broadcast_message(team_t *team, user_t *users)
{
    char team_id[37];
    int size = strlen(team->name) + strlen(team->description) + 65;
    char *message = malloc(sizeof(char) * size);

    if (message == NULL) {
        return;
    }
    uuid_unparse(team->uuid, team_id);
    sprintf(message, "TEAMCREATED %s\n\"%s\"\n\"%s\"\n",
        team_id, team->name, team->description);
    send_message_to_connected_users(message, users);
    free(message);
}

int createteam_cmd(tcp_client_t *client, server_t *server, char **message)
{
    team_t *team;
    user_t *user;

    if (message_args_nbr(message) != 3) {
        return (ERR_CMD);
    }
    user = get_user_from_socket(client->sock, server->users);
    if (user == NULL) {
        return (ERR_LOGIN);
    }
    team = create_team(message[1], message[2], user->uuid);
    if (team == NULL) {
        return (ERR_SERVER);
    }
    add_team(&server->teams, team);
    broadcast_message(team, server->users);
    return (NO_RESPONSE);
}