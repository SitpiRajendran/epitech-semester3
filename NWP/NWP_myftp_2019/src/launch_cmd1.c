/*
** EPITECH PROJECT, 2020
** NWP
** File description:
** launch_cmd1
*/

#include "ftp.h"

void launch_user(infos_t *srv, int i)
{
    if (strcmp("Anonymous", srv->arg) != 0)
        srv->user_ok = false;
    else
        srv->user_ok = true;
    srv->ret_msg = "331 User name okay, need password.\r\n";
}

void launch_pass(infos_t *srv, int i)
{
    if (srv->user_ok == false) {
        srv->login_ok = false;
        srv->ret_msg = "332 Need account for login.\r\n";
    } else {
        srv->login_ok = true;
        srv->ret_msg = "230 User logged in, proceed.\r\n";
    }
}

void launch_cdup(infos_t *srv, int i)
{
    if (srv->user_ok == false)
        srv->ret_msg = "530 Not logged in.\r\n";
    else {
        if (chdir("..") == -1)
            srv->ret_msg = "550 Requested action not taken. \
File unavailable (e.g., file not found, no access).\r\n";
        else
            srv->ret_msg = "200 Command okay.\r\n";
    }
}

void launch_cwd(infos_t *srv, int i)
{
    if (srv->user_ok == false)
        srv->ret_msg = "530 Not logged in.\r\n";
    else {
        if (chdir(srv->arg) == -1)
            srv->ret_msg = "550 Requested action not taken. \
File unavailable (e.g., file not found, no access).\r\n";
        else
            srv->ret_msg = "250 Requested file action okay, completed.\r\n";
    }
}

void launch_dele(infos_t *srv, int i)
{
    if (srv->user_ok == false) {
        srv->ret_msg = "530 Not logged in.\r\n";
        return;
    }
    if (remove(srv->arg) == -1)
        srv->ret_msg = "550 Requested action not taken. \
File unavailable (e.g., file not found, no access).\r\n";
    else
        srv->ret_msg = "250 Requested file action okay, completed.\r\n";
}