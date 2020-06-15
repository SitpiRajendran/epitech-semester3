/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client
*/

#include "tcp_client.h"
#include "client.h"

void disp_help(char **args, CLI_DATA *data)
{
    (void) args;
    (void) data;
    printf("My_Teams help menu:\nCOMMANDS:\n\t");
    printf("\"/help\": display all usefull informations of this program.\n");
    printf("\t\"/login\": .\n");
    printf("ERRORS MESSAGES:\n");
    printf("\t\"yes\": everything's good.\n");
}

int get_inputs(CLI_DATA *data, int server_sock)
{
    fd_set readfds;
    char buffer[1024];

    FD_ZERO(&readfds);
    FD_SET(server_sock, &readfds);
    FD_SET(0, &readfds);
    if (select(server_sock + 1, &readfds, NULL, NULL, NULL) == -1)
        return (84);
    if (FD_ISSET(0, &readfds)) {
        memset(buffer, 0, 1024);
        read(0, buffer, 1024);
        is_this_a_command(buffer, data);
    }
    if (FD_ISSET(server_sock, &readfds)) {
        memset(buffer, 0, 1024);
        if (read(server_sock, buffer, 1024) == 0)
            return printf("The server has closed the connection\n");
        whathappen(buffer, data);
    }
    return (0);
}

int client(const char *ip, int port)
{
    int server_sock = connect_to_server(ip, port);
    CLI_DATA data;
    int status;

    if (server_sock == -1)
        return (84);
    else
        data.sock = server_sock;
    data.connected = false;
    data.use_type = PERSONAL;
    while (1) {
        status = get_inputs(&data, server_sock);
        if (status == 84)
            return (84);
        else if (status != 0)
            return (0);
    }
    return (0);
}

void is_this_a_command(char *buffer, CLI_DATA *data)
{
    char **args = split_message(buffer, " \r\n");
    int used;
    void (*fptr[14])(char **, CLI_DATA *) =
        {&login_send, &logout_send, &userlist_send, &user_send, &send_send,
        &message_send, &disp_help, &sub_send, &unsub_send, &create_all_send,
        &use_send, &info_all_send, &subscribed_send, &list_all_send};
    const char *names[15] = {
        "/login", "/logout", "/users", "/user", "/send", "/messages", "/help",
        "/subscribe", "/unsubscribe", "/create", "/use", "/info", "/subscribed",
        "/list", NULL};

    if (args == NULL)
        return ((void) write(1, "ERR_CMD : Unknown command\n", 27));
    for (int i = 0; names[i] != NULL; i++)
        if (strcmp(args[0], names[i]) == 0) {
            (*fptr[i])(args, data);
            used = 1;
        }
    if (used != 1)
        write(1, "ERR_CMD : Unknown command\n", 27);
}

void whathappen(char *buffer, CLI_DATA *data)
{
    char **args = split_message(buffer, " \r\n");
    void (*fptr[32])(char **, CLI_DATA *) =
        { &login_receive, &logout_receive, &userlist_receive, &user_receive,
        &send_receive, &message_receive, &sub_receive, &unsub_receive,
        &create_team_receive, &create_chan_receive, &create_thread_receive,
        &create_reply_receive, &info_user_receive, &info_team_receive,
        &info_chan_receive, &info_thread_receive, &use_receive, &err_a,
        &err_a, &err_a, &err_a, &err_user, &err_team, &err_chan, &err_already,
        &err_thread, &sub_team_receive, &sub_user_receive, &teamlist_receive,
        &chanlist_receive, &threadlist_receive, &replylist_receive};
    const char *names[33] = { "LOGINOK", "LOGOUTOK", "USERLISTOK", "USEROK",
    "MESSAGEFROM", "MESSAGEOK", "SUBOK", "UNSUBOK", "TEAMCREATED",
    "CHANCREATED", "THREADCREA", "REPCREATED", "INFOUSEROK", "INFOTEAMOK",
    "INFOCHANOK", "INFOTHREADOK", "USEOK", "ERR_NOTSUB", "ERR_LOGIN",
    "ERR_SERVER", "ERR_CMD", "ERR_VALIDUSER", "ERR_UKN_TEAM", "ERR_UKN_CHAN",
    "ERR_ALREADY", "ERR_UKN_THRD", "TEAM", "USER", "LTEAM",
    "LCHAN", "LTHREAD", "LREPLY", NULL};

    for (int i = 0; names[i] != NULL; i++)
        if (strcmp(args[0], names[i]) == 0)
            (*fptr[i])(args, data);
}