##
## EPITECH PROJECT, 2018
## D11 - T1 - Makefile
## File description:
## makefile compiles your libmy
##

CC  = gcc -g3

SRC = 	string.c	\
	string_next.c	\
	string_next2.c	\
	string_next3.c

OBJ = $(SRC:.c=.o)

NAME = libstring.a

all: $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) *.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
