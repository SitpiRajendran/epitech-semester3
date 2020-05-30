##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile compiles your programs
##

SRC 	=	src/ex00.cpp

SRC_T 	=	src/ex00.cpp

OBJ_T = $(SRC_T:.cpp=.o)

NAME_T = unit_tests

CFLAGS += -I include -Wall -Wextra -Werror

FLAGS	=	--coverage -lcriterion

OBJ = $(SRC:.cpp=.o)

NAME = my_cat

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@rm -f *.gcno
	@rm -f *.gcda
	@rm -f tests/*.o
	@echo -e "\033[1;32mCleaning finished !\033[0m"

$(NAME): $(OBJ)
	@g++ -o $(NAME) $(OBJ) $(CFLAGS)
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_T)

re: fclean all

test: CFLAGS += -Wall -Wextra -g3
test: $(OBJ)
	@g++ -o $(NAME) $(OBJ) $(CFLAGS)
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"

tests_run: $(OBJ_T) $(OBJ)
	@g++ -o $(NAME_T) $(FLAGS) $(SRC_T) $(CFLAGS)
	./$(NAME_T)
	gcovr

fclean_t: clean
	@rm -f $(NAME)
	@rm -f $(NAME_T)

.PHONY: all clean fclean re test test_run fclean_t

.SILENT: $(OBJ) $(OBJ_T)
