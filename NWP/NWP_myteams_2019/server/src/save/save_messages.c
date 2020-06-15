/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** save_messages
*/

#include <stdio.h>
#include "definitions.h"

void save_message(int fd, message_t *message)
{
    char sender_id[37];
    char receiver_id[37];

    uuid_unparse(message->sender, sender_id);
    uuid_unparse(message->receiver, receiver_id);
    dprintf(fd, "MESSAGE %s %s %ld \"%s\"\n",
    sender_id, receiver_id, message->sent_time, message->message);
}

void save_messages(int fd, message_t *messages)
{
    message_t *cursor = messages;

    while (cursor) {
        save_message(fd, cursor);
        cursor = cursor->next;
    }
}
