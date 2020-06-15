/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** teams_receive
*/

#include "client.h"

void sub_receive(char **args, CLI_DATA *data)
{
    client_print_subscribed(data->uuid, args[1]);
}

void unsub_receive(char **args, CLI_DATA *data)
{
    client_print_unsubscribed(data->uuid, args[1]);
}

void err_already(char **args, CLI_DATA *data)
{
    (void) data;
    (void) args;
    client_error_already_exist();
}

void use_receive(char **args, CLI_DATA *data)
{
    data->use_type = atoi(args[1]);
    data->use_id = args[2];
    if (how_many_words(args) > 3)
        use_receive(&args[3], data);
}

void sub_team_receive(char **args, CLI_DATA*data)
{
    (void) data;
    client_print_teams(args[1], args[2], args[3]);
}
