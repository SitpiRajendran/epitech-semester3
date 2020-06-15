/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** save_replys
*/

#include <stdio.h>
#include "definitions.h"

void save_reply(int fd, reply_t *reply)
{
    char thread_id[37];
    char user_id[37];

    uuid_unparse(reply->thread_uuid, thread_id);
    uuid_unparse(reply->sender, user_id);
    dprintf(fd, "REPLY %s %s %ld \"%s\"\n",
    thread_id, user_id, reply->create_time, reply->body);
}

void save_replys(int fd, reply_t *replys)
{
    while (replys) {
        save_reply(fd, replys);
        replys = replys->next;
    }
}
