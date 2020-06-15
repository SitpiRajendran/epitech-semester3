/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/select.h>
#include <unistd.h>
#include "logging_client.h"
#include "utilities.h"

int client(const char *ip, int port);

enum USE_TYPE
{
    PERSONAL,
    TEAMS,
    CHANNELS,
    THREADS
};

typedef struct cli_data
{
    int sock;
    bool connected;
    char *uuid;
    char *username;
    int use_type;
    char *use_id;
} CLI_DATA;

void is_this_a_command(char *buffer, CLI_DATA *data);
void whathappen(char *buffer, CLI_DATA *data);

//SENDERS

void login_send(char **, CLI_DATA *data);
void logout_send(char **, CLI_DATA *data);

void userlist_send(char **args, CLI_DATA *data);
void user_send(char **args, CLI_DATA *data);
void send_send(char **args, CLI_DATA *data);
void message_send(char **args, CLI_DATA *data);

void sub_send(char **args, CLI_DATA *data);
void unsub_send(char **args, CLI_DATA *data);
void create_all_send(char **, CLI_DATA *data);
void info_all_send(char **args, CLI_DATA *data);
void list_all_send(char **args, CLI_DATA *data);

void use_send(char **args, CLI_DATA *data);
void subscribed_send(char **args, CLI_DATA *data);

//RECEIVERS
void login_receive(char **args, CLI_DATA *data);
void logout_receive(char **args, CLI_DATA *data);

void userlist_receive(char **args, CLI_DATA *data);
void user_receive(char **args, CLI_DATA *data);
void send_receive(char **args, CLI_DATA *data);
void message_receive(char **args, CLI_DATA *data);

void sub_receive(char **args, CLI_DATA *data);
void unsub_receive(char **args, CLI_DATA *data);
void sub_user_receive(char **args, CLI_DATA*data);
void sub_team_receive(char **args, CLI_DATA*data);

void create_team_receive(char **args, CLI_DATA *data);
void create_chan_receive(char **args, CLI_DATA *data);
void create_thread_receive(char **args, CLI_DATA *data);
void create_reply_receive(char **args, CLI_DATA *data);

void info_team_receive(char **info, CLI_DATA *data);
void info_chan_receive(char **info, CLI_DATA *data);
void info_thread_receive(char **info, CLI_DATA *data);
void info_user_receive(char **info, CLI_DATA *data);

void teamlist_receive(char **args, CLI_DATA *data);
void chanlist_receive(char **args, CLI_DATA *data);
void threadlist_receive(char **args, CLI_DATA *data);
void replylist_receive(char **args, CLI_DATA *data);

void use_receive(char **args, CLI_DATA *data);

//ERRORS
void err_a(char **args, CLI_DATA *data);
void err_user(char **args, CLI_DATA *data);
void err_team(char **args, CLI_DATA *data);
void err_chan(char **args, CLI_DATA *data);
void err_thread(char **args, CLI_DATA *data);
void err_already(char **args, CLI_DATA *data);

#endif /* !CLIENT_H_ */
