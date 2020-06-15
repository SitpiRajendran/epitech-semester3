/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"

void print_usage(void)
{
    puts("USAGE: ./myteams_server port\n");
    puts("       port  is the port number on wicht the server socket");
    puts(" listens.");
}

int main(int ac, char **av)
{
    if (ac != 2) {
        printf("Error: you must provide only one argument\n");
        print_usage();
        return (84);
    }
    if (strcmp(av[1], "-help") == 0) {
        print_usage();
        return (0);
    }
    return (server(atoi(av[1])));
}
