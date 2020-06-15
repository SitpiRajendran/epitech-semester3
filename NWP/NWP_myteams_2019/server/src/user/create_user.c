/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create_user
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "server.h"

void add_user_to_list(user_t *user, user_t **list)
{
    user_t *cursor = *list;

    if (*list == NULL) {
        printf("Add at beginning\n");
        *list = cursor;
        return;
    }
    while (cursor->next) {
        cursor = cursor->next;
    }
    cursor->next = user;
}

user_t *create_user(void)
{
    user_t *user = malloc(sizeof(user_t));

    if (user == NULL) {
        return (NULL);
    }
    memset(user->username, 0, MAX_NAME_LENGTH);
    memset(user->uuid, 0, 37);
    user->is_logged = 0;
    user->tcp_client = NULL;
    user->next = NULL;
    user->context = NONE;
    user->sub_teams = NULL;
    return (user);
}
