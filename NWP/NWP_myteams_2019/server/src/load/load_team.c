/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** load_team
*/

#include <stdlib.h>
#include <string.h>
#include "my_team.h"
#include "user.h"
#include "definitions.h"
#include "commands.h"

void add_node(linked_list_t *node, linked_list_t **list)
{
    linked_list_t *cursor = *list;

    if (*list == NULL) {
        *list = node;
        return;
    }
    while (cursor->next) {
        cursor = cursor->next;
    }
    cursor->next = node;
}

linked_list_t *create_node(void)
{
    linked_list_t *node = malloc(sizeof(linked_list_t));

    if (node == NULL) {
        return (NULL);
    }
    node->next = NULL;
    node->obj = NULL;
    return (node);
}

void link_user(const char *user_id, team_t *team, server_t *server)
{
    user_t *user = get_user_from_id(user_id, server->users);
    linked_list_t *team_node;
    linked_list_t *user_node;

    if (user == NULL) {
        return;
    }
    team_node = create_node();
    if (team_node == NULL) {
        return;
    }
    team_node->obj = user;
    add_node(team_node, &team->sub_users);
    user_node = create_node();
    if (user_node == NULL) {
        return;
    }
    user_node->obj = team;
    add_node(user_node, &user->sub_teams);
}

int load_team(server_t *server, char **words)
{
    team_t *team = alloc_team();

    if (team == NULL) {
        return (-1);
    }
    uuid_parse(words[1], team->uuid);
    team->create_time = atol(words[2]);
    strcpy(team->name, words[3]);
    strcpy(team->description, words[4]);
    for (int i = 5; words[i] != NULL; i++) {
        link_user(words[i], team, server);
    }
    if (server->teams == NULL) {
        server->teams = team;
        return (0);
    }
    add_team(&server->teams, team);
    return (0);
}
