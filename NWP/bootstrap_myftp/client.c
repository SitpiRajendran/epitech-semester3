/*
** EPITECH PROJECT, 2020
** bootstrap_myftp
** File description:
** client
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av)
{
    int hSocket;
    int valread;
    struct sockaddr_in adress;

    if ((hSocket = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return 84;
    }

    adress.sin_family = AF_INET;
    adress.sin_port = htons(atoi(av[2]));

    if(inet_pton(AF_INET, av[1], &adress.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return 84;
    }
    if(connect(hSocket, (struct sockaddr *)&adress, sizeof(struct sockaddr_in)) == -1) {
        printf("\nConnection Failed \n");
        return 84;
    }

    valread = send(hSocket , "hello" , strlen("hello") , 0 );
    return (0);
}