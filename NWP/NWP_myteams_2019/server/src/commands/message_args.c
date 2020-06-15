/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** message_args
*/

#include <stddef.h>
#include "tcp_structs.h"

int message_args_nbr(char **message)
{
    int args_nbr = 0;

    for (int i = 0; message[i] != NULL; i++) {
        args_nbr++;
    }
    return (args_nbr);
}
