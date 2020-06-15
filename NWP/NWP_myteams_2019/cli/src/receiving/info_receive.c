/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** commands4
*/

#include "client.h"

void info_team_receive(char **info, CLI_DATA *data)
{
    (void) data;
    if (how_many_words(info) == 4)
        client_print_team(info[1], info[2], info[3]);
}

void info_chan_receive(char **info, CLI_DATA *data)
{
    (void) data;
    if (how_many_words(info) == 4)
        client_print_channel(info[1], info[2], info[3]);
}

void info_thread_receive(char **info, CLI_DATA *data)
{
    (void) data;
    if (how_many_words(info) == 6)
        client_print_thread(info[1], info[2], atol(info[3]), info[4], info[5]);
}

void info_user_receive(char **info, CLI_DATA *data)
{
    (void) data;
    if (how_many_words(info) == 4)
        client_print_user(info[1], info[2], atoi(info[3]));
}