##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile compiles your programs
##

SRC =	src/main.py

NAME = groundhog

all: $(NAME)

clean:
	@rm -f $(NAME)

$(NAME): $(SRC)
	@cp $(SRC) $(NAME)
	@chmod 777 $(NAME)
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"

fclean: clean
	@echo -e "\033[1;32mCleaning finished !\033[0m"

re: fclean all

.PHONY: all clean fclean re