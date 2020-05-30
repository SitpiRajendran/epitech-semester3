##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile compiles your programs
##

SRC 	=	src/main.c	\
	src/menger.c

SRC_T 	=	src/main.c	\
	src/menger.c

OBJ_T = $(SRC_T:.c=.o)

NAME_T = unit_tests

CFLAGS += -std=gnu11 -Wall -Wextra -I include -lm

FLAGS	=	--coverage -lcriterion

OBJ = $(SRC:.c=.o)

NAME = menger

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

tests_run: $(OBJ_T) $(OBJ)
	@gcc -o $(NAME_T) $(FLAGS) $(SRC_T) $(CFLAGS)
	./$(NAME_T)
	gcovr

fclean_t: clean
	@rm -f $(NAME)
	@rm -f $(NAME_T)

.PHONY: all clean fclean re test test_run fclean_t

.SILENT: $(OBJ) $(OBJ_T)
