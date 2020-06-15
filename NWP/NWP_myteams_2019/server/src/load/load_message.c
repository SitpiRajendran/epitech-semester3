/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** load_message
*/

#include <stdlib.h>
#include "my_message.h"
#include "definitions.h"

int load_message(server_t *server, char **words)
{
    uuid_t sender_uuid;
    uuid_t receiver_uuid;
    message_t *message;

    uuid_parse(words[1], sender_uuid);
    uuid_parse(words[2], receiver_uuid);
    message = create_message(sender_uuid, receiver_uuid, words[4]);
    if (message == NULL) {
        return (-1);
    }
    message->sent_time = atol(words[3]);
    add_message_to_list(message, &server->messages);
    return (0);
}
