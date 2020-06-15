/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_init
*/

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include "server.h"
#include "tcp_server.h"

int set_socket(int port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in address = {0};

    if (sock == -1) {
        perror("socket");
        return (-1);
    }
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = INADDR_ANY;
    if (bind(sock, (struct sockaddr *)&address, sizeof(address)) == -1) {
        perror("bind");
        return (-1);
    }
    return (sock);
}

int init_tcp_server(tcp_server_t *server, int port)
{
    server->sock = set_socket(port);
    if (server->sock == -1 || listen(server->sock, MAX_CLIENTS) == -1) {
        perror("listen");
        return (-1);
    }
    server->clients = NULL;
    return (0);
}
