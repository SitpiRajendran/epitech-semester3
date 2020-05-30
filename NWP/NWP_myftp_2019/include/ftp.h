/*
** EPITECH PROJECT, 2020
** NWP
** File description:
** ftp
*/

#ifndef FTP_H_
#define FTP_H_

#include <arpa/inet.h>
#include <errno.h>
#include <dirent.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>

/* Data Struct */

typedef struct infos_s {
    struct sockaddr_in adress;
    int hSocket;
    int addrlen;
    int i;
    int new_socket;
    fd_set active_fd_set;
    char *path;
    bool user_ok;
    bool login_ok;
    bool passive;
    char *ret_msg;
    char *cmd;
    char *arg;
} infos_t;

/* args_handle.c */
int check_args(int ac, char **av);
void help(void);

/* error.c */
void error_handle(char *str, int value);

/* init.c */
struct sockaddr_in init_sockaddr(char *av);
int init_socket (struct sockaddr_in adress);
infos_t *init_struct(char *av);

/* cmd_handle.c */
void send_comm(infos_t *srv);
//int get_cmd_next(infos_t *srv);
void get_cmd(infos_t *srv, int socket);

/* launch_cmd.c */
void launch_user(infos_t *srv, int i);
void launch_pass(infos_t *srv, int i);
void launch_cdup(infos_t *srv, int i);
void launch_cwd(infos_t *srv, int i);
void launch_dele(infos_t *srv, int i);

void launch_pwd(infos_t *srv, int i);
void launch_help(infos_t *srv, int i);
void launch_noop(infos_t *srv, int i);
void launch_quit(infos_t *srv, int i);

void launch_pasv(infos_t *srv, int i);
void launch_retr(infos_t *srv, int i);
void launch_stor(infos_t *srv, int i);
void launch_list(infos_t *srv, int i);

#endif /* !FTP_H_ */
