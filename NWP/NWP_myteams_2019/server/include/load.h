/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** load
*/

#ifndef LOAD_H_
#define LOAD_H_

int load(server_t *server);
int load_user(server_t *server, char **words);
int load_message(server_t *server, char **words);
int load_team(server_t *server, char **words);

#endif /* !LOAD_H_ */
