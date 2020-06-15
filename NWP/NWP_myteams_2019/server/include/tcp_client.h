/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** tcp_client
*/

#include <stdbool.h>
#include "tcp_structs.h"

int create_client(tcp_client_t **clients, int sock);

void destroy_all_clients(tcp_client_t *clients);

tcp_client_t *remove_client_with_socket(int sock, tcp_client_t **clients);
