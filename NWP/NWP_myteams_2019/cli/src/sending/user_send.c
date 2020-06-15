/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user_send
*/

#include "client.h"

void userlist_send(char **args, CLI_DATA *data)
{
    (void) args;
    if (data->connected == true)
        dprintf(data->sock, "USERLIST\r\n");
    else
        client_error_unauthorized();
}

void user_send(char **args, CLI_DATA *data)
{
    if (data->connected == true && how_many_words(args) == 2)
        dprintf(data->sock, "USER \"%s\"\r\n", args[1]);
    else
        client_error_unauthorized();
}

void send_send(char **args, CLI_DATA *data)
{
    if (data->connected == true && how_many_words(args) == 3) {
        if (strlen(args[1]) > MAX_BODY_LENGTH)
            client_error_unauthorized();
        else
            dprintf(data->sock, "SEND \"%s\" \"%s\"\r\n", args[1], args[2]);
    } else
        client_error_unauthorized();
}

void message_send(char **args, CLI_DATA *data)
{
    if (data->connected == true && how_many_words(args) == 2) {
        dprintf(data->sock, "MESSAGE \"%s\"\r\n", args[1]);
    } else
        client_error_unauthorized();
}