/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** commands4
*/

#include "client.h"

void create_team_send(char *id, char *desc, CLI_DATA *data)
{
    if (data->connected == true) {
        if (strlen(desc) > MAX_DESCRIPTION_LENGTH ||
            strlen(id) > MAX_NAME_LENGTH)
            client_error_unauthorized();
        else
            dprintf(data->sock, "CREATETEAM \"%s\" \"%s\"\r\n", id, desc);
    } else
        client_error_unauthorized();
}

void create_chan_send(char *id, char *desc, CLI_DATA *data)
{
    if (data->connected == true) {
        if (strlen(desc) > MAX_DESCRIPTION_LENGTH ||
            strlen(id) > MAX_NAME_LENGTH)
            client_error_unauthorized();
        else
            dprintf(data->sock, "CREATECHAN \"%s\" \"%s\"\r\n", id, desc);
    } else
        client_error_unauthorized();
}

void create_thread_send(char *id, char *desc, CLI_DATA *data)
{
    if (data->connected == true) {
        if (strlen(desc) > MAX_BODY_LENGTH || strlen(id) > MAX_NAME_LENGTH)
            client_error_unauthorized();
        else
            dprintf(data->sock, "CREATETHREAD \"%s\" \"%s\"\r\n", id, desc);
    } else
        client_error_unauthorized();
}

void create_reply_send(char *message, CLI_DATA *data)
{
    if (data->connected == true) {
        if (strlen(message) > MAX_BODY_LENGTH)
            client_error_unauthorized();
        else
            dprintf(data->sock, "CREATEREP \"%s\"\r\n", message);
    } else
        client_error_unauthorized();
}

void create_all_send(char **args, CLI_DATA *data)
{
    if (data->use_type == THREADS && how_many_words(args) == 2)
        create_reply_send(args[1], data);
    if (data->use_type == PERSONAL && how_many_words(args) == 3)
        create_team_send(args[1], args[2], data);
    if (data->use_type == TEAMS && how_many_words(args) == 3)
        create_chan_send(args[1], args[2], data);
    if (data->use_type == CHANNELS && how_many_words(args) == 3)
        create_thread_send(args[1], args[2], data);
}