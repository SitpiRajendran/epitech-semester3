/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** init_server
*/

#include "definitions.h"

void init_server(server_t *server)
{
    server->teams = NULL;
    server->channels = NULL;
    server->threads = NULL;
    server->replys = NULL;
    server->users = NULL;
    server->messages = NULL;
}
