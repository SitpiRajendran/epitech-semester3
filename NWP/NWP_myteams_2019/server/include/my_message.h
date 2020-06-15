/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** my_message
*/

#ifndef MY_MESSAGE_H_
#define MY_MESSAGE_H_

#include <uuid/uuid.h>
#include "definitions.h"

message_t *create_message(uuid_t sender, uuid_t receiver, const char *message);
void add_message_to_list(message_t *message, message_t **messages_list);

#endif /* !MY_MESSAGE_H_ */
