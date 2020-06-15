/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create_thread
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "my_thread.h"
#include "logging_server.h"

thread_t *alloc_thread(void)
{
    thread_t *thread = malloc(sizeof(thread_t));

    if (thread == NULL) {
        printf("Error malloc\n");
        return (NULL);
    }
    memset(thread->title, 0, MAX_NAME_LENGTH);
    memset(thread->message, 0, MAX_BODY_LENGTH);
    return (thread);
}

void add_thread(thread_t **threads, thread_t *thread_to_add)
{
    thread_t *cursor;

    if (*threads == NULL) {
        *threads = thread_to_add;
        return;
    }
    cursor = *threads;
    while (cursor->next) {
        cursor = cursor->next;
    }
    cursor->next = thread_to_add;
}

void log_create_thread(uuid_t thread_uuid, uuid_t channel_uuid,
                        uuid_t user_uuid, const char *message)
{
    char thread_id[37];
    char channel_id[37];
    char user_id[37];

    uuid_unparse(thread_uuid, thread_id);
    uuid_unparse(channel_uuid, channel_id);
    uuid_unparse(user_uuid, user_id);
    server_event_thread_created(channel_id, thread_id, user_id, message);
}

thread_t *create_thread(const char *title, const char *message,
                        uuid_t channel_uuid, uuid_t user_uuid)
{
    thread_t *thread = alloc_thread();

    if (thread == NULL) {
        return (NULL);
    }
    strncpy(thread->title, title, MAX_NAME_LENGTH);
    strncpy(thread->message, message, MAX_BODY_LENGTH);
    uuid_copy(thread->create_user, user_uuid);
    uuid_copy(thread->channel_uuid, channel_uuid);
    uuid_generate_random(thread->uuid);
    thread->create_time = time(NULL);
    thread->next = NULL;
    log_create_thread(thread->uuid, channel_uuid, user_uuid, message);
    return (thread);
}
