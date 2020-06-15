/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** login_cmd
*/

#include <string.h>
#include <uuid/uuid.h>
#include <stdio.h>
#include <stdlib.h>
#include "logging_server.h"
#include "commands.h"
#include "user.h"

static user_t *init_user(user_t **users, const char *username)
{
    user_t *user = create_user();

    if (user == NULL) {
        return (NULL);
    }
    if (*users == NULL) {
        *users = user;
    } else {
        add_user_to_list(user, users);
    }
    strncpy(user->username, username, MAX_NAME_LENGTH);
    uuid_generate_random(user->uuid);
    return (user);
}

static void broadcast_message(const char *name, const char *id, user_t *user)
{
    int lenght = strlen(name) + 48;
    char *message = malloc(sizeof(char) * lenght);

    if (message == NULL) {
        return;
    }
    sprintf(message, "LOGINOK\n%s %s\r\n", name, id);
    send_message_to_connected_users(message, user);
    free(message);
}

static user_t *add_user(server_t *server, const char *username)
{
    char user_id[37];
    user_t *user = init_user(&server->users, username);

    if (user == NULL) {
        return (NULL);
    }
    uuid_unparse(user->uuid, user_id);
    server_event_user_created(user_id, user->username);
    return (user);
}

int login_user(tcp_client_t *client, server_t *server, char **message)
{
    user_t *user;
    char user_id[37];

    if (message_args_nbr(message) != 2) {
        return (ERR_LOGIN);
    }
    user = get_user_from_name(message[1], server->users);
    if (user == NULL) {
        user = add_user(server, message[1]);
        if (user == NULL) {
            return (ERR_LOGIN);
        }
    }
    user->tcp_client = client;
    user->is_logged = true;
    uuid_unparse(user->uuid, user_id);
    server_event_user_logged_in(user_id);
    broadcast_message(user->username, user_id, server->users);
    return (NO_RESPONSE);
}
