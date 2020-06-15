/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** connection_send
*/

#include "client.h"

void login_send(char **args, CLI_DATA *data)
{
    if (data->connected == false && how_many_words(args) == 2) {
        data->username = args[1];
        dprintf(data->sock, "LOGIN \"%s\"\r\n", args[1]);
    } else
        client_error_unauthorized();
}

void logout_send(char **args, CLI_DATA *data)
{
    (void) args;
    if (data->connected == true)
        dprintf(data->sock, "LOGOUT\r\n");
    else
        client_error_unauthorized();
}
