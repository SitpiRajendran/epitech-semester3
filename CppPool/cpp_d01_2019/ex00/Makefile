##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile compiles your programs
##

SRC 	=	src/z.c

CFLAGS += -I include -std=gnu11 -Wall -Wextra

FLAGS	=	--coverage -lcriterion

OBJ = $(SRC:.c=.o)

NAME = z

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@rm -f *.gcno
	@rm -f *.gcda
	@rm -f tests/*.o
	@echo -e "\033[1;32mCleaning finished !\033[0m"

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_T)

re: fclean all

test: CFLAGS += -Wall -Wextra -g3
test: $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"

.PHONY: all clean fclean re test

.SILENT: $(OBJ)