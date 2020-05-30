##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile compiles your programs
##

SRC =	src/GetUserHostName.cpp						\
		src/date.cpp								\
		src/graphical_interface.cpp					\
		src/Sys.cpp 								\
		src/CoreModel.cpp 							\
		src/Frequency.cpp 							\
		src/NWindow.cpp 							\
		src/ram.cpp									\
		src/graphical_i.cpp							\
		src/initialize_graphicals_data.cpp			\
		src/swap.cpp								\
		src/cpu.cpp									\
		src/IsDisped.cpp 							\
		src/network.cpp								\
		src/main.cpp

SRC_T 	=	tests/test.c	\

OBJ = $(SRC:.cpp=.o)

OBJ_T = $(SRC_T:.cpp=.o)

CPPFLAGS = -I ./include

NAME = MyGKrellm

SFML =	-lsfml-system	\
		-lsfml-window	\
		-lsfml-graphics	\

NCURSES =	-lncurses	\

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo -e "\033[1;32mCleaning finished !\033[0m"

$(NAME): $(OBJ)
	@g++ -o $(NAME) $(OBJ) $(SFML) $(NCURSES)
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: CPPFLAGS += -Wall -Wextra -g3
test: $(OBJ)
	@g++ -o $(NAME) $(OBJ) $(SFML) $(NCURSES)
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"
	@rm -f $(OBJ)

tests_run: CPPFLAGS += -Wall -Wextra -g3
tests_run: $(OBJ_T) $(OBJ)
	@g++ -o $(NAME_T) $(FLAGS) $(SRC_T) $(CPPFLAGS)
	./$(NAME_T)
	gcovr

fclean_t: clean
	@rm -f $(NAME)
	@rm -f $(NAME_T)

.PHONY: all clean fclean re test tests_run fclean_t

.SILENT: $(OBJ) $(OBJ_T)
