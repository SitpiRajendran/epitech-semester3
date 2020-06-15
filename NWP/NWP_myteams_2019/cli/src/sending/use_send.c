/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** use
*/

#include "client.h"

void use_send(char **args, CLI_DATA *data)
{
    switch (how_many_words(args))
    {
    case 1:
        dprintf(data->sock, "USE\r\n");
        break;
    case 2:
        dprintf(data->sock, "USE \"%s\"\r\n", args[1]);
        break;
    case 3:
        dprintf(data->sock, "USE \"%s\" \"%s\"\r\n", args[1], args[2]);
        break;
    case 4:
        dprintf(data->sock, "USE \"%s\" \"%s\" \"%s\"\r\n",
        args[1], args[2], args[3]);
        break;
    default:
        client_error_unauthorized();
        break;
    }
}