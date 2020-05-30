##
## EPITECH PROJECT, 2020
## FUN_wolfram_2019
## File description:
## Makefile
##

SRC =	src/main.hs	\
		src/Arguments.hs	\
		src/Launch.hs	\
		src/30.hs	\
		src/90.hs	\
		src/110.hs	\
		src/tools.hs	\

NAME = wolfram

all: $(NAME)

clean:
	@rm -f src/*.hi
	@rm -f src/*.o

$(NAME):
	@ghc $(SRC) -o $(NAME)
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re