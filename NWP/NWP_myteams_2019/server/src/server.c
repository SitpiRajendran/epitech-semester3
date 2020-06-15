/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server
*/

#include <sys/select.h>
#include <stddef.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include "tcp_server.h"
#include "commands.h"
#include "server.h"
#include "save.h"
#include "load.h"

void sig_handler(int sig)
{
    sig = sig;
}

int server_loop(tcp_server_t *tcp_server, server_t *srv)
{
    fd_set readfds;
    int highest_fd = 1;
    tcp_message_t *messages = NULL;

    signal(SIGINT, sig_handler);
    while (1) {
        highest_fd = get_highest_fd(tcp_server->sock, tcp_server->clients);
        add_fds(tcp_server->clients, tcp_server->sock, &readfds);
        if (select(highest_fd + 1, &readfds, NULL, NULL, NULL) < 0) {
            return (errno);
        }
        accept_new_conections(tcp_server, &readfds);
        messages = get_messages(&tcp_server->clients, &readfds);
        manage_messages(&messages, srv);
        destroy_all_messages(&messages);
    }
    return (0);
}

int server(int port)
{
    tcp_server_t tcp_server;
    server_t server;
    int status;

    init_server(&server);
    if (load(&server) == -1) {
        printf("Could not load ressources.\n");
    }
    if (init_tcp_server(&tcp_server, port) == -1) {
        return (ERROR);
    }
    status = server_loop(&tcp_server, &server);
    if (status != EINTR && status != 0) {
        return (ERROR);
    }
    destroy_tcp_server(&tcp_server);
    save_data(&server);
    return (0);
}
