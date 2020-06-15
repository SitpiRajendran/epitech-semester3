/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create_reply
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my_reply.h"
#include "logging_server.h"

reply_t *alloc_reply(void)
{
    reply_t *reply = malloc(sizeof(reply_t));

    if (reply == NULL) {
        printf("Error malloc\n");
        return (NULL);
    }
    return (reply);
}

void add_reply(reply_t **replys, reply_t *reply_to_add)
{
    reply_t *cursor;

    if (*replys == NULL) {
        *replys = reply_to_add;
        return;
    }
    cursor = *replys;
    while (cursor->next) {
        cursor = cursor->next;
    }
    cursor->next = reply_to_add;
}

void log_create_reply(uuid_t thread_uuid, uuid_t user_uuid, const char *msg)
{
    char thread_id[37];
    char user_id[37];

    uuid_unparse(thread_uuid, thread_id);
    uuid_unparse(user_uuid, user_id);
    server_event_thread_new_message(thread_id, user_id, msg);
}

reply_t *create_reply(const char *msg, uuid_t sender, uuid_t thread_uuid)
{
    reply_t *reply = alloc_reply();

    if (reply == NULL) {
        return (NULL);
    }
    strncpy(reply->body, msg, MAX_BODY_LENGTH);
    uuid_copy(reply->thread_uuid, thread_uuid);
    uuid_copy(reply->sender, sender);
    reply->create_time = time(NULL);
    reply->next = NULL;
    log_create_reply(sender, thread_uuid, msg);
    return (reply);
}
