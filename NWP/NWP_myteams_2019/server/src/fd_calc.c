/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** fd_calc
*/

#include <sys/select.h>
#include "definitions.h"

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