/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user
*/

#ifndef USER_H_
#define USER_H_

#include "definitions.h"

user_t *create_user(void);
void add_user_to_list(user_t *user, user_t **list);
int add_subscribed_team(user_t *user, team_t *team);
void remove_sub_team(team_t *team, user_t *user);

#endif /* !USER_H_ */
