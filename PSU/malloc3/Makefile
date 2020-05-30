##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile compiles your programs
##

SRC =	src/malloc.c	\

SRC_T 	=	tests/test.c	\

OBJ = $(SRC:.c=.o)

OBJ_T = $(SRC_T:.c=.o)

CPPFLAGS = -I ./include -fpic -shared 

NAME = libmy_malloc.so

all: $(NAME)

clean:
	@rm -f $(OBJ)

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CPPFLAGS)
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@echo -e "\033[1;32mCleaning finished !\033[0m"

re: fclean all

test: CPPFLAGS += -Wall -Wextra -g3
test: $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CPPFLAGS)
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"
	@rm -f $(OBJ)

tests_run: CPPFLAGS += -Wall -Wextra -g3
tests_run: $(OBJ_T) $(OBJ)
	@gcc -fpic -shared -o $(NAME) $(OBJ) $(SRC_T)
	./$(NAME_T)
	gcovr

fclean_t: clean
	@rm -f $(NAME)
	@rm -f $(NAME_T)

.PHONY: all clean fclean re test tests_run fclean_t

.SILENT: $(OBJ) $(OBJ_T)
