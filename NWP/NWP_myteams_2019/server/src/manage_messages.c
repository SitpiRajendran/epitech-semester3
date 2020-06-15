/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** manage_messages
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "commands.h"
#include "utilities.h"

int (*get_function(const char *command))(tcp_client_t *, server_t *, char **)
{
    int (*fptr[22])(tcp_client_t *, server_t *, char **) = {
    &login_user, &logout_user, &user_cmd, &send_cmd, &message_cmd,
    &userlist_cmd, &createteam_cmd, &use_cmd, &sub_cmd, &sublist_cmd,
    &sublistteam_cmd, &createchan_cmd, &createthread_cmd, &infoteam_cmd,
    &createrep_cmd, &listteam_cmd, &listchan_cmd, &listthread_cmd,
    &listreply_cmd, &infochan_cmd, &infothread_cmd, &unsub_cmd};
    const char *names[22] = {
    "LOGIN", "LOGOUT", "USER", "SEND", "MESSAGE", "USERLIST", "CREATETEAM",
    "USE", "SUB", "SUBLIST", "SUBLISTTEAM", "CREATECHAN", "CREATETHREAD",
    "INFOTEAM", "CREATEREP", "LISTTEAM", "LISTCHAN", "LISTTHREAD", "LISTREP",
    "INFOCHAN", "INFOTHREAD", "UNSUB"};

    for (int i = 0; i < 22; i++) {
        if (strcmp(command, names[i]) == 0) {
            return (fptr[i]);
        }
    }
    return (NULL);
}

int manage_message(tcp_message_t *message, server_t *server)
{
    char **message_words = split_message(message->message, " \n\r");
    response_e resp;
    int (*fptr)(tcp_client_t *, server_t *, char **);

    if (message_words == NULL) {
        return (ERROR);
    }
    fptr = get_function(message_words[0]);
    if (fptr != NULL) {
        resp = (*fptr)(message->client, server, message_words);
        send_response(resp, message->client->sock);
    }
    free_double_array(message_words);
    return (0);
}

int manage_messages(tcp_message_t **messages, server_t *server)
{
    tcp_message_t *cursor = *messages;

    while (cursor) {
        if (manage_message(cursor, server) == 84) {
            return (ERROR);
        }
        cursor = cursor->next;
    }
    return (0);
}
