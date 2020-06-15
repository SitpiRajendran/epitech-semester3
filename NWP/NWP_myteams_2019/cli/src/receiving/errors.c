/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** errors
*/

#include "client.h"
// OR receive a message type "ERR_NOTSUB" "ERR_LOGIN" "ERR_CMD" "ERR_SERVER"
// OR receive a message type "ERR_VALIDUSER 015646"
// OR receive a message type "ERR_UKN_TEAM 015646"
// OR receive a message type "ERR_UKN_CHAN 015646
// OR receive a message type "ERR_UKN_THRD 015646

void err_a(char **args, CLI_DATA *data)
{
    (void) data;
    (void) args;
    client_error_unauthorized();
}

void err_user(char **args, CLI_DATA *data)
{
    (void) data;
    client_error_unknown_user(args[1]);
}

void err_team(char **args, CLI_DATA *data)
{
    (void) data;
    client_error_unknown_team(args[1]);
}

void err_chan(char **args, CLI_DATA *data)
{
    (void) data;
    client_error_unknown_channel(args[1]);
}

void err_thread(char **args, CLI_DATA *data)
{
    (void) data;
    client_error_unknown_thread(args[1]);
}