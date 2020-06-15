/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** destroy_clients
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "tcp_client.h"

void destroy_client(tcp_client_t *client)
{
    if (client->sock != -1) {
        close(client->sock);
    }
}

void remove_first_client(tcp_client_t **clients)
{
    tcp_client_t *next;

    if (*clients == NULL) {
        return;
    }
    next = (*clients)->next;
    destroy_client(*clients);
    free(*clients);
    *clients = next;
}

tcp_client_t *remove_client_with_socket(int sock, tcp_client_t **clients)
{
    tcp_client_t *cursor = *clients;
    tcp_client_t *prev = NULL;

    if (cursor->sock == sock) {
        remove_first_client(clients);
        return (*clients);
    }
    while (cursor->next) {
        prev = cursor;
        cursor = cursor->next;
        if (cursor->sock == sock) {
            prev->next = cursor->next;
            destroy_client(cursor);
            free(cursor);
            return (prev);
        }
    }
    return (NULL);
}

void destroy_all_clients(tcp_client_t *clients)
{
    tcp_client_t *cursor = clients;

    while (clients) {
        clients = clients->next;
        destroy_client(cursor);
        free(cursor);
        cursor = clients;
    }
}
