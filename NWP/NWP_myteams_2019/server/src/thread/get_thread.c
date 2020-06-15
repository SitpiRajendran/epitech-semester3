/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** get_thread
*/

#include "my_thread.h"

thread_t *get_thread_from_uuid(uuid_t uuid, thread_t *threads)
{
    thread_t *cursor = threads;

    while (cursor) {
        if (uuid_compare(uuid, cursor->uuid) == 0) {
            return (cursor);
        }
        cursor = cursor->next;
    }
    return (NULL);
}

thread_t *get_thread_from_id(const char *id, thread_t *threads)
{
    uuid_t uuid;
    thread_t *cursor = threads;

    uuid_parse(id, uuid);
    while (cursor) {
        if (uuid_compare(uuid, cursor->uuid) == 0) {
            return (cursor);
        }
        cursor = cursor->next;
    }
    return (NULL);
}
