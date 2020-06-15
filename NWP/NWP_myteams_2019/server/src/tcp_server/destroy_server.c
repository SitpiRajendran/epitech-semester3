/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** destroy_server
*/

#include <unistd.h>
#include "tcp_server.h"
#include "tcp_client.h"

void destroy_tcp_server(tcp_server_t *server)
{
    destroy_all_clients(server->clients);
    close(server->sock);
}
