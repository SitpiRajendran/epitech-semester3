/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** teams_send
*/

#include "client.h"

void sub_send(char **args, CLI_DATA *data)
{
    if (data->connected == true && how_many_words(args) == 2) {
        dprintf(data->sock, "SUB \"%s\"\r\n", args[1]);
    } else
        client_error_unauthorized();
}

void unsub_send(char **args, CLI_DATA *data)
{
    if (data->connected == true && how_many_words(args) == 2) {
        dprintf(data->sock, "UNSUB \"%s\"\r\n", args[1]);
    } else
        client_error_unauthorized();
}

void subscribed_send(char **args, CLI_DATA *data)
{
    if (data->connected == true && how_many_words(args) == 1) {
        dprintf(data->sock, "SUBLIST\r\n");
    } else if (data->connected == true && how_many_words(args) == 2) {
        dprintf(data->sock, "SUBLISTTEAM \"%s\"\r\n", args[1]);
    } else
        client_error_unauthorized();
}