/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** infoteam_cmd
*/

#include <stdio.h>
#include "commands.h"
#include "my_team.h"

static void send_team_infos(int socket, const char *team_id, team_t *team)
{
    dprintf(socket, "INFOTEAMOK %s\n\"%s\"\n\"%s\"\r\n",
    team_id, team->name, team->description);
}

int infoteam_cmd(tcp_client_t *client, server_t *server, char **message)
{
    team_t *team;

    if (message_args_nbr(message) != 2) {
        return (ERR_CMD);
    }
    if (get_user_from_socket(client->sock, server->users) == NULL) {
        return (ERR_LOGIN);
    }
    team = get_team_from_id(message[1], server->teams);
    if (team == NULL) {
        send_response_with_str(ERR_UKN_TEAM, client->sock, message[1]);
        return (NO_RESPONSE);
    }
    send_team_infos(client->sock, message[1], team);
    return (NO_RESPONSE);
}
