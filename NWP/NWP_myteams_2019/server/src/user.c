/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server
*/

#include <sys/types.h>
#include <stddef.h>
#include <stdio.h>
#include "tcp_server.h"

int get_highest_fd(int server_fd, tcp_client_t *clients)
{
    tcp_client_t *cursor = clients;
    int highest_fd = 0;

    while (cursor) {
        if (cursor->sock > 0 && cursor->sock > highest_fd) {
            highest_fd = cursor->sock;
        }
        cursor = cursor->next;
    }
    if (server_fd > highest_fd) {
        return (server_fd);
    }
    return (highest_fd);
}

void add_fds(tcp_client_t *clients, int server_sock, fd_set *set)
{
    FD_ZERO(set);
    for (tcp_client_t *cursor = clients; cursor; cursor = cursor->next) {
        FD_SET(cursor->sock, set);
    }
    FD_SET(server_sock, set);
}

void display_clients(tcp_client_t *clients)
{
    tcp_client_t *cursor = clients;

    if (!cursor) {
        printf("No clients connected\n");
    }
    while (cursor) {
        printf("Client sock: %d, is logged: %d\n",
        cursor->sock, cursor->is_logged);
        cursor = cursor->next;
    }
}

int server(int port)
{
    tcp_server_t server;
    fd_set readfds;
    int highest_fd;

    if (init_server(&server, port) == -1) {
        return (84);
    }
    while (1) {
        highest_fd = get_highest_fd(server.sock, server.clients);
        add_fds(server.clients, server.sock, &readfds);
        if (select(highest_fd + 1, &readfds, NULL, NULL, NULL) == -1) {
            perror("select");
            return (84);
        }
        accept_new_conections(&server, &readfds);
        check_sockets(&server.clients, &readfds);
        display_clients(server.clients);
    }
    destroy_server(&server);
    return (0);
}
