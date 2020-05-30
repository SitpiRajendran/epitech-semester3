/*
** EPITECH PROJECT, 2020
** NWP
** File description:
** cmd_handle
*/

#include "ftp.h"

void send_comm(infos_t *srv)
{
    fprintf(stderr, "[SEND] : **%s**\n", srv->ret_msg);
    write(srv->new_socket, srv->ret_msg, strlen(srv->ret_msg));
}

int get_cmd_next(infos_t *srv)
{
    int i = 0;

    if (strcmp(srv->cmd, "NOOP") == 0)
        launch_noop(srv, i++);
    if (strcmp(srv->cmd, "HELP") == 0)
        launch_help(srv, i++);
    if (strcmp(srv->cmd, "PASV") == 0)
        launch_pasv(srv, i++);
    if (strcmp(srv->cmd, "RETR") == 0)
        launch_retr(srv, i++);
    if (strcmp(srv->cmd, "STOR") == 0)
        launch_stor(srv, i++);
    if (strcmp(srv->cmd, "LIST") == 0)
        launch_list(srv, i++);
    return i;
}

void get_cmd(infos_t *srv, int socket)
{
    int i = 0;

    if (strcmp(srv->cmd, "USER") == 0)
        launch_user(srv, i++);
    if (strcmp(srv->cmd, "PASS") == 0)
        launch_pass(srv, i++);
    if (strcmp(srv->cmd, "CDUP") == 0)
        launch_cdup(srv, i++);
    if (strcmp(srv->cmd, "CWD") == 0)
        launch_cwd(srv, i++);
    if (strcmp(srv->cmd, "DELE") == 0)
        launch_dele(srv, i++);
    if (strcmp(srv->cmd, "PWD") == 0)
        launch_pwd(srv, i++);
    if (strcmp(srv->cmd, "QUIT") == 0)
        launch_quit(srv, i++);
    i += get_cmd_next(srv);
    if (i == 0)
        srv->ret_msg = "500 Wrong command.\r\n";
    send_comm(srv);
}