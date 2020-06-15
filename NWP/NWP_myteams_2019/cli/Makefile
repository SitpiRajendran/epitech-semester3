##
## EPITECH PROJECT, 2020
## NWP_myteams_2019
## File description:
## Makefile
##

SRC		=		src/main.c						\
				src/client.c					\
				src/split_message.c		\
				src/word.c		\
				src/tcp_client/connection.c		\
				src/sending/connection_send.c		\
				src/sending/user_send.c		\
				src/sending/teams_send.c		\
				src/sending/use_send.c		\
				src/sending/create_send.c		\
				src/sending/info_list_send.c		\
				src/receiving/connection_receive.c		\
				src/receiving/user_receive.c		\
				src/receiving/teams_receive.c		\
				src/receiving/create_receive.c		\
				src/receiving/info_receive.c		\
				src/receiving/list_receive.c		\
				src/receiving/errors.c

OBJ		=		$(SRC:.c=.o)

CFLAGS	=		-Wall -Werror -Wextra -I./include/ -I../libs/myteams/ -g3

NAME	=		myteams_cli

CC		=		gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L../libs/myteams/ -lmyteams
	mv $(NAME) ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
