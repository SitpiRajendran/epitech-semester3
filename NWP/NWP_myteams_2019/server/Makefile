##
## EPITECH PROJECT, 2020
## NWP_myteams_2019
## File description:
## Makefile
##

SRC		=		src/main.c								\
				src/server.c							\
				src/init_server.c						\
				src/manage_messages.c					\
				src/tcp_server/accept_connections.c		\
				src/tcp_server/get_messages.c			\
				src/tcp_server/create_client.c			\
				src/tcp_server/destroy_clients.c		\
				src/tcp_server/server_init.c			\
				src/tcp_server/destroy_server.c			\
				src/tcp_server/send_message.c			\
				src/tcp_server/message.c				\
				src/team/create_team.c					\
				src/team/get_team.c						\
				src/team/add_sub_user.c					\
				src/team/is_in_team.c					\
				src/team/remove_sub_user.c				\
				src/channel/create_channel.c			\
				src/channel/get_channel.c				\
				src/thread/create_thread.c				\
				src/thread/get_thread.c					\
				src/message/create_message.c			\
				src/message/add_message_to_list.c		\
				src/reply/create_reply.c				\
				src/commands/message_args.c				\
				src/commands/send_response.c			\
				src/commands/get_user.c					\
				src/commands/login_cmd.c				\
				src/commands/logout_cmd.c				\
				src/commands/user_cmd.c					\
				src/commands/send_cmd.c					\
				src/commands/message_cmd.c				\
				src/commands/userlist_cmd.c				\
				src/commands/createteam_cmd.c			\
				src/commands/use_cmd.c					\
				src/commands/sub_cmd.c					\
				src/commands/sublist_cmd.c				\
				src/commands/sublistteam_cmd.c			\
				src/commands/createchan_cmd.c			\
				src/commands/createthread_cmd.c			\
				src/commands/infoteam_cmd.c				\
				src/commands/createrep_cmd.c			\
				src/commands/listteam_cmd.c				\
				src/commands/listchan_cmd.c				\
				src/commands/listthread_cmd.c			\
				src/commands/listrep_cmd.c				\
				src/commands/infochan_cmd.c				\
				src/commands/infothread_cmd.c			\
				src/commands/unsub_cmd.c				\
				src/commands/set_context.c				\
				src/user/create_user.c					\
				src/user/add_subscribed_team.c			\
				src/user/remove_sub_team.c				\
				src/save/save.c							\
				src/save/save_users.c					\
				src/save/save_messages.c				\
				src/save/save_teams.c					\
				src/save/save_chans.c					\
				src/save/save_threads.c					\
				src/save/save_replys.c					\
				src/load/load.c							\
				src/load/load_user.c					\
				src/load/load_message.c					\
				src/load/load_team.c					\
				src/free_double_array.c					\
				src/split_message.c						\
				src/word.c								\
				src/fd_calc.c							\

OBJ		=		$(SRC:.c=.o)

CFLAGS	=		-Wall -Werror -Wextra -I./include/ -I../libs/myteams/ -g3

NAME	=		myteams_server

CC		=		gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -luuid -L../libs/myteams/ -lmyteams
	mv $(NAME) ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
