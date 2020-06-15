/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** commands4
*/

#include "client.h"

void create_team_receive(char **args, CLI_DATA *data)
{
    (void) data;
    client_print_team_created(args[1], args[2], args[3]);
}

void create_chan_receive(char **args, CLI_DATA *data)
{
    (void) data;
    client_print_channel_created(args[1], args[2], args[3]);
}

void create_thread_receive(char **args, CLI_DATA *data)
{
    (void) data;
    client_print_thread_created(args[1], args[2], atol(args[3]),
    args[4], args[5]);
}

void create_reply_receive(char **args, CLI_DATA *data)
{
    (void) data;
    client_print_reply_created(args[1], args[2], atol(args[3]), args[4]);
}
