/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create_message
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "definitions.h"

message_t *alloc_message(void)
{
    message_t *message = malloc(sizeof(message_t));

    if (message == NULL) {
        printf("Error malloc\n");
        return (NULL);
    }
    return (message);
}

message_t *create_message(uuid_t sender, uuid_t receiver, const char *message)
{
    message_t *msg = alloc_message();

    if (msg == NULL) {
        return (NULL);
    }
    uuid_copy(msg->sender, sender);
    uuid_copy(msg->receiver, receiver);
    strcpy(msg->message, message);
    msg->sent_time = time(NULL);
    msg->next = NULL;
    return (msg);
}
