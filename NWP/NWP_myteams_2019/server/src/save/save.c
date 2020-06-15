/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** save
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "definitions.h"
#include "save.h"

int save_data(server_t *server)
{
    int fd = open("save.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);

    if (fd == -1) {
        return (-1);
    }
    printf("Saving data\n");
    save_users(fd, server->users);
    save_messages(fd, server->messages);
    save_teams(fd, server->teams);
    save_chans(fd, server->channels);
    save_threads(fd, server->threads);
    save_replys(fd, server->replys);
    close(fd);
    return (0);
}
