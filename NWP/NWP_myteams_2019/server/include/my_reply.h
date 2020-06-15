/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** my_reply
*/

#ifndef MY_reply_H_
#define MY_reply_H_

#include "definitions.h"

reply_t *create_reply(const char *msg, uuid_t sender, uuid_t thread_uuid);

void add_reply(reply_t **replys, reply_t *reply_to_add);

#endif /* !MY_reply_H_ */
