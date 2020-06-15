/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** commands4
*/

#include "client.h"

void info_all_send(char **args, CLI_DATA *data)
{
    (void) args;
    if (data->use_type == PERSONAL)
        dprintf(data->sock, "INFOUSER \"%s\"\r\n", data->uuid);
    if (data->use_type == TEAMS)
        dprintf(data->sock, "INFOTEAM \"%s\"\r\n", data->use_id);
    if (data->use_type == CHANNELS)
        dprintf(data->sock, "INFOCHAN \"%s\"\r\n", data->use_id);
    if (data->use_type == THREADS)
        dprintf(data->sock, "INFOTHREAD \"%s\"\r\n", data->use_id);
}

void list_all_send(char **args, CLI_DATA *data)
{
    (void) args;
    if (data->use_type == PERSONAL)
        dprintf(data->sock, "LISTTEAM\r\n");
    if (data->use_type == TEAMS)
        dprintf(data->sock, "LISTCHAN\r\n");
    if (data->use_type == CHANNELS)
        dprintf(data->sock, "LISTTHREAD\r\n");
    if (data->use_type == THREADS)
        dprintf(data->sock, "LISTREP\r\n");
}