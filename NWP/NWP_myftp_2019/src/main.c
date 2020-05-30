/*
** EPITECH PROJECT, 2020
** NWP - NWP_myftp_2019
** File description:
** main
*/

#include "ftp.h"

int read_client(int i, infos_t *srv)
{
    char buffer[256];
    int nbytes = read(i, buffer, 256);

    if (nbytes < 0)
        error_handle("[ERROR] : Cannot Read", 84);
    else if (nbytes == 0)
        return -1;
    else {
        fprintf(stderr, "[RECEIVED] : **%s**\n", buffer);
        sscanf(buffer, "%s %s", srv->cmd, srv->arg);
        get_cmd(srv, i);
        return 0;
    }
}

int launch_next(infos_t *srv, fd_set read)
{
    if (FD_ISSET(srv->i, &read)) {
        if (srv->i == srv->hSocket) {
            if ((srv->new_socket = accept(srv->hSocket,
            (struct sockaddr *) &(srv->adress),
            (socklen_t *) &(srv->addrlen))) == -1)
                error_handle("[ERROR] : accept", 84);
            srv->ret_msg = "220 Service ready for new user.\r\n";
            fprintf(stderr, "[LOGS] : Server Launch\n");
            send_comm(srv);
            FD_SET(srv->new_socket, &(srv->active_fd_set));
        } else {
            if (read_client(srv->i, srv) == -1) {
                close(srv->i);
                FD_CLR(srv->i, &(srv->active_fd_set));
            }
        }
    }
}

int launch(char **av)
{
    infos_t *srv = init_struct(av[1]);
    fd_set read_fd_set;

    chdir(srv->path);
    FD_ZERO(&(srv->active_fd_set));
    FD_SET(srv->hSocket, &(srv->active_fd_set));

    while (1) {
        read_fd_set = srv->active_fd_set;
        if (select(FD_SETSIZE, &read_fd_set, NULL, NULL, NULL) < 0)
            error_handle("[ERROR] : select", 84);
        for (int i = 0; i < FD_SETSIZE; i++) {
            srv->i = i;
            launch_next(srv, read_fd_set);
        }
    }
}

int main(int ac, char **av)
{
    check_args(ac, av);
    return launch(av);
}

