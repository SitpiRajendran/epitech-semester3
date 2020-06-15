/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** add_message_to_list
*/

#include <stdio.h>
#include "my_message.h"

void add_message_to_list(message_t *message, message_t **messages_list)
{
    message_t *cursor = *messages_list;

    if (*messages_list == NULL) {
        *messages_list = message;
        return;
    }
    while (cursor->next) {
        cursor = cursor->next;
    }
    cursor->next = message;
}
