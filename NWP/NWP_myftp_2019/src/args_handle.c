/*
** EPITECH PROJECT, 2020
** NWP
** File description:
** args_handle
*/

#include "ftp.h"

void help(void)
{
    printf("USAGE: ./myftp port path\n");
    printf("\tport\tis the port number on which the server socket listens\n\t");
    printf("path\tis the path to the home directory for the Anonymous user\n");
    exit(0);
}

int check_args(int ac, char **av)
{
    if (ac >= 2 && !strcmp(av[1], "-help"))
        help();
    if (ac != 3)
        error_handle("ERROR : Wrong Parameters Numbers", 84);
    if (atoi(av[1]) <= 0)
        error_handle("ERROR : Port value is incorrect", 84);
    if (opendir(av[2]) == NULL)
        error_handle("ERROR : Path isn't correct", 84);
    return 0;
}