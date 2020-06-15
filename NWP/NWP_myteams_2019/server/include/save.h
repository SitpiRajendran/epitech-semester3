/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** save
*/

#ifndef SAVE_H_
#define SAVE_H_

#include "definitions.h"

int save_data(server_t *server);
void save_users(int fd, user_t *users);
void save_messages(int fd, message_t *messages);
void save_teams(int fd, team_t *teams);
void save_chans(int fd, channel_t *channels);
void save_threads(int fd, thread_t *threads);
void save_replys(int fd, reply_t *replys);

#endif /* !SAVE_H_ */
