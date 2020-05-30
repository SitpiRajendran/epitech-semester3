/*
** EPITECH PROJECT, 2020
** NWP
** File description:
** launch_cmd3
*/

#include "ftp.h"

void launch_pasv(infos_t *srv, int i)
{
    if (srv->user_ok == false)
        srv->ret_msg = "530 Not logged in.\r\n";
    else {
        srv->passive = true;
        srv->ret_msg = "227 Entering Passive Mode (h1,h2,h3,h4,p1,p2).\r\n";
    }
}

void launch_retr(infos_t *srv, int i)
{
    if (srv->passive == false)
        srv->ret_msg = "425 Can't open data connection.\r\n";
    else {
        srv->ret_msg = "150 File status okay; about to open data connection.\r\n";
        send_comm(srv);
        srv->ret_msg = "226 Closing data connection.\r\n";
    }
}

void launch_stor(infos_t *srv, int i)
{
    if (srv->passive == false)
        srv->ret_msg = "425 Can't open data connection.\r\n";
    else {
        srv->ret_msg = "150 File status okay; about to open data connection.\r\n";
        send_comm(srv);
        srv->ret_msg = "226 Closing data connection.\r\n";
    }
}

void launch_list(infos_t *srv, int i)
{
    if (srv->passive == false)
        srv->ret_msg = "425 Can't open data connection.\r\n";
    else {
        srv->ret_msg = "150 File status okay; about to open data connection.\r\n";
        send_comm(srv);
        srv->ret_msg = "226 Closing data connection.\r\n";
    }
}