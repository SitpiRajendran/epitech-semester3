/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** load
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "definitions.h"
#include "utilities.h"
#include "load.h"

int load_ressource(server_t *server, char *line)
{
    int (*fptr[3])(server_t *, char **) = {
        &load_user, load_message, &load_team};
    const char *ressources[3] = {"USER", "MESSAGE", "TEAM"};
    char **words = split_message(line, " \n");

    if (words == NULL) {
        return (-1);
    }
    for (int i = 0; i != 3; i++) {
        if (strcmp(words[0], ressources[i]) == 0) {
            fptr[i](server, words);
            return (0);
        }
    }
    free_double_array(words);
    return (0);
}

int load(server_t *server)
{
    FILE *fd = fopen("save.txt", "r");
    char *line = NULL;
    size_t n = 0;

    if (fd == NULL) {
        printf("Could not open save file.\n");
        return (-1);
    }
    while (getline(&line, &n, fd) != -1) {
        load_ressource(server, line);
        free(line);
        line = NULL;
        n = 0;
    }
    fclose(fd);
    return (0);
}
