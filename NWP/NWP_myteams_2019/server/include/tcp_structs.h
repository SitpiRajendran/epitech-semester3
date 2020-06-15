/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** tcp_structs
*/

#ifndef TCP_STRUCTS_H_
#define TCP_STRUCTS_H_

#include <stdbool.h>

typedef struct tcp_client_s {
    int sock;
    struct tcp_client_s *next;
} tcp_client_t;

typedef struct tcp_server_s {
    int sock;
    tcp_client_t *clients;
} tcp_server_t;

typedef struct tcp_message_s {
    tcp_client_t *client;
    char *message;
    struct tcp_message_s *next;
} tcp_message_t;

#endif /* !TCP_STRUCTS_H_ */
