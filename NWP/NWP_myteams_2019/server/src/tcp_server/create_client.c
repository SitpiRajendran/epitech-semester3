/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create_client
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tcp_client.h"

void add_client_to_list(tcp_client_t *new_client, tcp_client_t **list)
{
    tcp_client_t *cursor = *list;

    if (*list == NULL) {
        *list = new_client;
        return;
    }
    while (cursor->next != NULL) {
        cursor = cursor->next;
    }
    cursor->next = new_client;
}

int create_client(tcp_client_t **clients, int sock)
{
    tcp_client_t *new_client;

    new_client = malloc(sizeof(tcp_client_t));
    if (new_client == NULL) {
        return (-1);
    }
    new_client->next = NULL;
    new_client->sock = sock;
    add_client_to_list(new_client, clients);
    return (0);
}
