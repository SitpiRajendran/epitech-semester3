/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** connection_receive
*/

#include "client.h"

void login_receive(char **args, CLI_DATA *data)
{
    if (data->connected == false)
        if (strcmp(data->username, args[1]) == 0) {
            data->connected = true;
            data->uuid = args[2];
        }
    client_event_loggedin(args[2], args[1]);
}

void logout_receive(char **args, CLI_DATA *data)
{
    if (data->connected == true) {
        if (strcmp(data->username, args[1]) == 0) {
            data->connected = false;
            client_event_loggedout(data->uuid, data->username);
        } else
            client_event_loggedout(args[1], args[2]);
    } else
        client_error_unauthorized();
}