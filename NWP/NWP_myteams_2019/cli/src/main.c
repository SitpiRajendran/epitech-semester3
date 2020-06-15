/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "client.h"

void display_usage(void)
{
    printf("USAGE: ./myteams_cli ip port\n");
    printf("       ip    is the server ip address on ");
    printf("which the server socket listens\n");
    printf("       port  is the port number on ");
    printf("which the server socket listens\n");
}

int main(int ac, char **av)
{
    if (ac < 2) {
        display_usage();
        return (84);
    }
    if (strcmp(av[1], "--help") == 0) {
        display_usage();
        return (0);
    }
    if (ac != 3) {
        printf("Error: you must provide 2 arguments.\n");
        display_usage();
        return (84);
    }
    return (client(av[1], atoi(av[2])));
}
