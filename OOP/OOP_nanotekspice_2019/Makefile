##
## EPITECH PROJECT, 2020
## CppPool
## File description:
## Makefile
##

SRC = 	component/C4001.cpp			\
		component/Input.cpp			\
		component/Output.cpp		\
		component/Pin.cpp			\
		component/True.cpp 			\
		src/argumentParsing.cpp 	\
		src/checkExecution.cpp 		\
		src/compare.cpp 			\
		src/Parser.cpp 				\
		src/main.cpp 				\

CXX = g++

CXXFLAGS = -W -Wall -Wextra

CPPFLAGS = -I ./include

NAME = nanotekspice

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: all
	@./$(NAME)

.PHONY: all clean fclean re test