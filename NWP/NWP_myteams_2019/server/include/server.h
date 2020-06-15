/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#include "definitions.h"

int server(int port);
void init_server(server_t *server);
void add_fds(tcp_client_t *clients, int server_sock, fd_set *set);
int get_highest_fd(int server_fd, tcp_client_t *clients);

#endif /* !SERVER_H_ */
