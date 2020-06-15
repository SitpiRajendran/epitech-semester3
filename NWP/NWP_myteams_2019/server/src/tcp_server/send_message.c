/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** send_message
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>

void send_message(int sock, const char *message)
{
    dprintf(sock, "%s\r\n", message);
}
