/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** check_sockets
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tcp_server.h"
#include "tcp_client.h"
#include "commands.h"

void add_message(tcp_message_t *message, tcp_message_t **message_list)
{
    tcp_message_t *cursor = *message_list;

    if (*message_list == NULL) {
        *message_list = message;
        return;
    }
    while (cursor->next) {
        cursor = cursor->next;
    }
    cursor->next = message;
}

tcp_message_t *get_client_message(tcp_client_t *client, fd_set *readfds)
{
    tcp_message_t *message = NULL;
    char buffer[1024];
    int status = 0;

    if (FD_ISSET(client->sock, readfds)) {
        message = create_tcp_message();
        if (message == NULL) {
            return (NULL);
        }
        memset(buffer, 0, 1024);
        status = read(client->sock, buffer, 1024);
        message->message = malloc(sizeof(char) * (strlen(buffer) + 1));
        strcpy(message->message, buffer);
        if (status == 0) {
            message->message = NULL;
            printf("Client disconnected\n");
        }
        message->client = client;
    }
    return (message);
}

tcp_message_t *get_messages(tcp_client_t **clients, fd_set *readfds)
{
    tcp_client_t *cursor = *clients;
    tcp_message_t *messages = NULL;
    tcp_message_t *received_message;

    while (cursor != NULL) {
        received_message = get_client_message(cursor, readfds);
        if (received_message && received_message->message == NULL) {
            cursor = remove_client_with_socket(cursor->sock, clients);
        } else if (received_message) {
            add_message(received_message, &messages);
        }
        if (cursor) {
            cursor = cursor->next;
        }
    }
    return (messages);
}
