/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** load_user
*/

#include <string.h>
#include <stdio.h>
#include "user.h"
#include "definitions.h"
#include "logging_server.h"

int load_user(server_t *server, char **words)
{
    user_t *user = create_user();

    if (user == NULL) {
        return (-1);
    }
    uuid_parse(words[1], user->uuid);
    strcpy(user->username, words[2]);
    if (server->users == NULL) {
        server->users = user;
    } else {
        add_user_to_list(user, &server->users);
    }
    server_event_user_loaded(words[1], words[2]);
    return (0);
}
