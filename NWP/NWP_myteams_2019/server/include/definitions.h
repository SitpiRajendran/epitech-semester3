/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** definitions
*/

#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

#include <uuid/uuid.h>
#include <stdbool.h>
#include "tcp_structs.h"

#define MAX_CLIENTS 10
#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512
#define ERROR 84

typedef enum use {
    NONE,
    TEAM,
    CHANNEL,
    THREAD
} use_e;

typedef struct linked_list_s {
    void *obj;
    struct linked_list_s *next;
} linked_list_t;

typedef struct team_s {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    time_t create_time;
    uuid_t uuid;
    linked_list_t *sub_users;
    struct team_s *next;
} team_t;

typedef struct channel_s {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    time_t create_time;
    uuid_t uuid;
    uuid_t team_uuid;
    struct channel_s *next;
} channel_t;

typedef struct thread_s {
    char title[MAX_NAME_LENGTH];
    char message[MAX_BODY_LENGTH];
    time_t create_time;
    uuid_t create_user;
    uuid_t uuid;
    uuid_t channel_uuid;
    struct thread_s *next;
} thread_t;

typedef struct reply_s {
    char body[MAX_BODY_LENGTH];
    time_t create_time;
    uuid_t sender;
    uuid_t thread_uuid;
    struct reply_s *next;
} reply_t;

typedef struct user_s {
    char username[MAX_NAME_LENGTH];
    bool is_logged;
    uuid_t uuid;
    tcp_client_t *tcp_client;
    use_e context;
    uuid_t context_uuid;
    linked_list_t *sub_teams;
    struct user_s *next;
} user_t;

typedef struct message_s {
    uuid_t sender;
    uuid_t receiver;
    char message[MAX_BODY_LENGTH];
    time_t sent_time;
    struct message_s *next;
} message_t;

typedef struct server_s {
    team_t *teams;
    channel_t *channels;
    thread_t *threads;
    reply_t *replys;
    message_t *messages;
    user_t *users;
} server_t;

#endif /* !DEFINITIONS_H_ */
