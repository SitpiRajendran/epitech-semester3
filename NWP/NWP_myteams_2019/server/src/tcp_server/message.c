/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** message
*/

#include <stdio.h>
#include <stdlib.h>
#include "tcp_structs.h"

void destroy_message(tcp_message_t *message)
{
    if (message->message) {
        free(message->message);
    }
    free(message);
}

void destroy_all_messages(tcp_message_t **messages)
{
    tcp_message_t *save = *messages;
    tcp_message_t *cursor = *messages;

    if (messages == NULL || *messages == NULL) {
        return;
    }
    while (cursor) {
        save = cursor;
        cursor = cursor->next;
        destroy_message(save);
    }
}

tcp_message_t *create_tcp_message(void)
{
    tcp_message_t *message = malloc(sizeof(tcp_message_t));

    if (message == NULL) {
        printf("Error malloc\n");
        return (NULL);
    }
    message->client = NULL;
    message->message = NULL;
    message->next = NULL;
    return (message);
}
