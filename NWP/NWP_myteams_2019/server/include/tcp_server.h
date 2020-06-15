/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** tcp_server
*/

#ifndef TCP_SERVER_H_
#define TCP_SERVER_H_

#include <sys/select.h>
#include "tcp_structs.h"

int init_tcp_server(tcp_server_t *server, int port);
void destroy_tcp_server(tcp_server_t *server);
int accept_new_conections(tcp_server_t *server, fd_set *readfds);
void send_message(int sock, const char *message);

// Get all the messages sent by the connected clients.
// You must free the messages by yourself using destroy_message
// function for each node of the linked list.
tcp_message_t *get_messages(tcp_client_t **clients, fd_set *readfds);

tcp_message_t *create_tcp_message(void);
void destroy_message(tcp_message_t *message);
void destroy_all_messages(tcp_message_t **messages);

#endif /* !TCP_SERVER_H_ */
