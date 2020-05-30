/*
** EPITECH PROJECT, 2020
** bootstrap_myftp
** File description:
** main
*/

#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>

int read_client(int fd)
{
    char buffer[255];
    int nbytes = read(fd, buffer, 255);

    if (nbytes < 0) {
        printf("ERROR : SOCKET\n");
        exit(84);
    } else if (nbytes == 0) {
        return -1;
    } else {
        fprintf(stderr, "Server got message: `%s`\n", buffer);
        return 0;
    }
}

int main(int ac, char **av) {
    int hSocket = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in adress;
    int addrlen = sizeof(adress);
    int new_socket, pid;
    fd_set active_fd_set, read_fd_set;

    adress.sin_family = AF_INET;
    adress.sin_addr.s_addr = INADDR_ANY;
    adress.sin_port = htons(atoi(av[1]));

    if (bind(hSocket, (struct sockaddr *) &adress, sizeof(struct sockaddr_in)) == -1) {
        printf("ERROR : SOCKET\n");
        return 84;
    }
    if (listen(hSocket, 20) == -1) {
        printf("ERROR : Queue\n");
        return 84;
    }

    FD_ZERO(&active_fd_set);
    FD_SET(hSocket, &active_fd_set);

    while (1) {
        read_fd_set = active_fd_set;
        if (select(FD_SETSIZE, &read_fd_set, NULL, NULL, NULL) < 0) {
            printf("Select\n");
            exit(84);
        }

        for (int i = 0; i < FD_SETSIZE; i++) {
            if (FD_ISSET(i, &read_fd_set)) {
                if (i == hSocket) {
                    if ((new_socket = accept(hSocket, (struct sockaddr *) &adress, (socklen_t *) &addrlen))  == -1) {
                        printf("ERROR : Accept\n");
                        return 84;
                    }
                    write(new_socket, "220\n", 4);
                    fprintf(stderr, "Server: connect from host %s, port %hu.\n", inet_ntoa (adress.sin_addr), ntohs(addrlen));
                    FD_SET(new_socket, &active_fd_set);
                } else {
                    fprintf(stderr, "Server: connect from host %s, port %hu.\n", inet_ntoa (adress.sin_addr), ntohs(addrlen));
                    if (read_client(i) == -1) {
                        close(i);
                        FD_CLR(i, &active_fd_set);
                    }
                }
            }
        }
/*         if ((new_socket = accept(hSocket, (struct sockaddr *) &adress, (socklen_t *) &addrlen))  == -1) {
            printf("ERROR : Accept\n");
            return 84;
        }
        pid = fork();
        if (pid == 0) {
            fprintf(stderr, "Server: connect from host %s, port %hu.\n", inet_ntoa (adress.sin_addr), ntohs(addrlen));
            if (write(new_socket, "Hello World!!!", 15) == -1) {
                printf("ERROR : Accept\n");
                return 84;
            }
        } else {
            close(new_socket);
        } */
    }
    return 0;
}