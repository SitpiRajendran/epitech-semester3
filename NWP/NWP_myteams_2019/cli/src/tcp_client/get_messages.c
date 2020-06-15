/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** get_messages
*/

#include <sys/select.h>
#include <string.h>
#include <unistd.h>

char *get_messages(int sock, fd_set *readfds)
{
    char buffer[1024];

    if (FD_ISSET(sock, readfds)) {
        memset(buffer, 0, 1024);
        if (read(sock, buffer, 1024) == 0) {
            close(sock);
            return ("\0");
        }
        return (buffer);
    }
    return (NULL);
}
