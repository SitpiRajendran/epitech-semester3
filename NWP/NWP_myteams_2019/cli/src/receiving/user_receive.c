/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user_receive
*/

#include "client.h"

void userlist_receive(char **args, CLI_DATA *data)
{
    client_print_users(args[1], args[2], atoi(args[3]));
    if (how_many_words(args) > 4)
        userlist_receive(&args[4], data);
}

void user_receive(char **args, CLI_DATA *data)
{
    if (data->connected == true && how_many_words(args) == 4) {
        client_print_user(args[1], args[2], atoi(args[3]));
    } else
        client_error_unauthorized();
}

void send_receive(char **args, CLI_DATA *data)
{
    if (data->connected == true && how_many_words(args) == 3) {
        client_event_private_message_received(args[1], args[2]);
    } else
        client_error_unauthorized();
}

void message_receive(char **args, CLI_DATA *data)
{
    client_private_message_print_messages(args[1], atol(args[3]), args[2]);
    if (how_many_words(args) > 4)
        message_receive(&args[4], data);
}

void sub_user_receive(char **args, CLI_DATA*data)
{
    (void) data;
    client_print_users(args[1], args[2], atoi(args[3]));
}