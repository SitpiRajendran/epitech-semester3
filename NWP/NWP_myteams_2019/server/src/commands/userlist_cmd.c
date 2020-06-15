/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** userlist_cmd
*/

#include <stdio.h>
#include "commands.h"

void send_users(int socket, user_t *users)
{
    user_t *cursor = users;
    char user_id[37];

    while (cursor) {
        uuid_unparse(cursor->uuid, user_id);
        dprintf(socket, "USERLISTOK %s\n\"%s\"\n%d\r\n",
        user_id, cursor->username, cursor->is_logged);
        cursor = cursor->next;
    }
}

int userlist_cmd(tcp_client_t *client, server_t *server, char **message)
{
    if (get_user_from_socket(client->sock, server->users) == NULL) {
        return (ERR_LOGIN);
    }
    if (message_args_nbr(message) != 1) {
        return (ERR_CMD);
    }
    send_users(client->sock, server->users);
    return (NO_RESPONSE);
}
