/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** accept_connections
*/

#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "tcp_client.h"

int accept_new_conections(tcp_server_t *server, fd_set *readfds)
{
    struct sockaddr_in addr;
    socklen_t socklen = sizeof(addr);
    int new_sock;

    if (!FD_ISSET(server->sock, readfds)) {
        return (0);
    }
    new_sock = accept(server->sock, (struct sockaddr *)&addr, &socklen);
    if (new_sock == -1) {
        perror("new_sock");
        return (-1);
    }
    if (create_client(&server->clients, new_sock) == -1) {
        printf("Error: could not create a new client.");
    }
    printf("New connection.\n");
    write(new_sock, "Welcome !\n", 11);
    return (0);
}
