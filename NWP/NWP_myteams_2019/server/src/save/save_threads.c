/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** save_threads
*/

#include <stdio.h>
#include "definitions.h"

void save_thread(int fd, thread_t *thread)
{
    char thread_id[37];
    char user_id[37];

    uuid_unparse(thread->uuid, thread_id);
    uuid_unparse(thread->create_user, user_id);
    dprintf(fd, "THREAD %s %s %ld \"%s\" \"%s\"\n",
    thread_id, user_id, thread->create_time, thread->title, thread->message);
}

void save_threads(int fd, thread_t *threads)
{
    while (threads) {
        save_thread(fd, threads);
        threads = threads->next;
    }
}
