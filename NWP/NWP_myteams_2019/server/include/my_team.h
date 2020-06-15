/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** my_team header
*/

#ifndef MY_TEAM_H_
#define MY_TEAM_H_

#include "definitions.h"

team_t *create_team(const char *name, const char *description, uuid_t user);

void add_team(team_t **teams, team_t *team_to_add);

team_t *get_team_from_uuid(uuid_t uuid, team_t *teams);

team_t *get_team_from_id(const char *id, team_t *teams);

int add_sub_user(team_t *team, user_t *user);

int is_in_team(user_t *user, team_t *team);

void remove_sub_user(team_t *team, user_t *user);

team_t *alloc_team(void);

#endif /* !MY_TEAM_H_ */
