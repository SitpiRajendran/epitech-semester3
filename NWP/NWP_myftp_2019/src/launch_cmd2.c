/*
** EPITECH PROJECT, 2020
** NWP
** File description:
** launch_cmd2
*/

#include "ftp.h"

void launch_pwd(infos_t *srv, int i)
{
    char cwd[1024];
    char *string;

    if (srv->user_ok == false)
        srv->ret_msg = "530 Not logged in.\r\n";
    else {
        if (getcwd(cwd, sizeof(cwd)) == NULL)
            srv->ret_msg = "550 Requested action not taken. \
File unavailable (e.g., file not found, no access).\r\n";
        else {
            string = malloc(sizeof(char) *(strlen(cwd) + 16));
            strcat(string, "257 ");
            strcat(string, cwd);
            strcat(string, " created.\r\n");
            srv->ret_msg = string;
        }
    }
}

void launch_help(infos_t *srv, int i)
{
    if (srv->user_ok == false)
        srv->ret_msg = "530 Not logged in.\r\n";
    else
        srv->ret_msg = "214 HELP COMMAND\ncwd cdup del pwd help quit\r\n";
}

void launch_noop(infos_t *srv, int i)
{
    if (srv->user_ok == false)
        srv->ret_msg = "530 Not logged in.\r\n";
    else
        srv->ret_msg = "200 Command okay.\r\n";
}

void launch_quit(infos_t *srv, int i)
{
    srv->user_ok = false;
    srv->ret_msg = "221 Service closing control conenction.\n\
Logged out if appropriate\r\n";

    close(srv->i);
    FD_CLR(srv->i, &(srv->active_fd_set));
}