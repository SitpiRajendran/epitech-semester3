/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** commands
*/

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include "definitions.h"
#include "tcp_structs.h"

typedef enum response_e {
    OK,
    SUBOK,
    UNSUBOK,
    ERR_SERVER,
    ERR_LOGIN,
    ERR_CMD,
    ERR_VALIDUSER,
    ERR_UKN_TEAM,
    ERR_UKN_CHAN,
    ERR_UKN_THRD,
    ERR_NOTSUB,
    NO_RESPONSE
} response_e;

int manage_messages(tcp_message_t **messages, server_t *server);
int message_args_nbr(char **message);
void send_response(response_e type, int socket);
void send_response_with_str(response_e type, int socket, const char *str);
void send_message_to_connected_users(const char *message, user_t *users);

user_t *get_user_from_name(const char *username, user_t *users);
user_t *get_user_from_socket(int socket, user_t *users);
user_t *get_user_from_uuid(uuid_t uuid, user_t *users);
user_t *get_user_from_id(const char *id, user_t *users);

void set_thread(user_t *user, char **message, server_t *server);
void set_channel(user_t *user, char **message, server_t *server);
response_e set_team(user_t *user, char **message, server_t *server);

int login_user(tcp_client_t *client, server_t *server, char **message);
int logout_user(tcp_client_t *client, server_t *server, char **message);
int user_cmd(tcp_client_t *client, server_t *server, char **message);
int send_cmd(tcp_client_t *tcp_client, server_t *server, char **message);
int message_cmd(tcp_client_t *client, server_t *server, char **message);
int userlist_cmd(tcp_client_t *client, server_t *server, char **message);
int use_cmd(tcp_client_t *client, server_t *server, char **message);
int sub_cmd(tcp_client_t *client, server_t *server, char **message);
int sublist_cmd(tcp_client_t *client, server_t *server, char **message);
int sublistteam_cmd(tcp_client_t *client, server_t *server, char **message);
int createteam_cmd(tcp_client_t *client, server_t *server, char **message);
int createchan_cmd(tcp_client_t *client, server_t *server, char **message);
int createthread_cmd(tcp_client_t *client, server_t *server, char **message);
int infoteam_cmd(tcp_client_t *client, server_t *server, char **message);
int createrep_cmd(tcp_client_t *client, server_t *server, char **message);
int listteam_cmd(tcp_client_t *client, server_t *server, char **message);
int listchan_cmd(tcp_client_t *client, server_t *server, char **message);
int listthread_cmd(tcp_client_t *client, server_t *server, char **message);
int listreply_cmd(tcp_client_t *client, server_t *server, char **message);
int infochan_cmd(tcp_client_t *client, server_t *server, char **message);
int infothread_cmd(tcp_client_t *client, server_t *server, char **message);
int unsub_cmd(tcp_client_t *client, server_t *server, char **message);

#endif /* !COMMANDS_H_ */
