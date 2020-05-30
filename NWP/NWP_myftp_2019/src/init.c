/*
** EPITECH PROJECT, 2020
** NWP
** File description:
** init
*/

#include "ftp.h"

struct sockaddr_in init_sockaddr(char *av)
{
    struct sockaddr_in adress;

    adress.sin_family = AF_INET;
    adress.sin_addr.s_addr = INADDR_ANY;
    adress.sin_port = htons(atoi(av));

    return adress;
}

int init_socket(struct sockaddr_in adress)
{
    int hSocket = socket(PF_INET, SOCK_STREAM, 0);

    if (bind(hSocket, (struct sockaddr *) &adress,
    sizeof(struct sockaddr_in)) == -1) {
        printf("ERROR : Binding Socket\n");
        exit(84);
    }
    if (listen(hSocket, 20) == -1) {
        printf("ERROR : Listen Socket\n");
        exit(84);
    }
    return hSocket;
}

infos_t *init_struct(char *av)
{
    infos_t *all_infos = malloc(sizeof(infos_t));

    all_infos->adress = init_sockaddr(av);
    all_infos->hSocket = init_socket(all_infos->adress);
    all_infos->addrlen = sizeof(all_infos->adress);

    all_infos->user_ok = false;
    all_infos->login_ok = false;
    all_infos->passive = false;
    all_infos->cmd = malloc(sizeof(char) * 5);
    all_infos->arg = malloc(sizeof(char) * 253);
    all_infos->ret_msg = "";
    all_infos->path = av;

    return all_infos;
}