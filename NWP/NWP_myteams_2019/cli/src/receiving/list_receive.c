/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** commands4
*/

#include "client.h"

void teamlist_receive(char **args, CLI_DATA *data)
{
    (void) data;
    client_print_teams(args[1], args[2], args[3]);
    if (how_many_words(args) > 4)
        teamlist_receive(&args[4], data);
}

void chanlist_receive(char **args, CLI_DATA *data)
{
    (void) data;
    client_team_print_channels(args[1], args[2], args[3]);
    if (how_many_words(args) > 4)
        chanlist_receive(&args[4], data);
}

void threadlist_receive(char **args, CLI_DATA *data)
{
    (void) data;
    client_channel_print_threads(args[1], args[2], atol(args[3]),
    args[4], args[5]);
    if (how_many_words(args) > 6)
        threadlist_receive(&args[6], data);
}

void replylist_receive(char **args, CLI_DATA *data)
{
    (void) data;
    client_thread_print_replies(args[1], args[2], atol(args[3]), args[4]);
    if (how_many_words(args) > 5)
        threadlist_receive(&args[5], data);
}