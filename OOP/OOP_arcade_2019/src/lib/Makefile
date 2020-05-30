##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

CXX		=	g++

NAME	=	../../lib/lib_arcade_ncurses.so

SRC		=	Ncurses.cpp

OBJ		=	$(SRC:%.cpp=%.o)

CPPFLAGS	=  -I./../../include/

CXXFLAGS = -g -shared -fPIC -lncurses

RM		=	rm -rf

all		:	$(NAME)

$(NAME) : $(OBJ)
		$(CXX) $(OBJ) -o $(NAME) $(CXXFLAGS) $(CPPFLAGS)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re 		: fclean all

##tests_run : $(LDFLAGS) += --coverage -lcriterion
##tests_run : $(CXXFLAGS) += -Wall -Wextra -std=c++11
##tests_run : clean $(OBJ)
##			$(CC) -o $(NAME) $(SRC) $(CPPFLAGS) $(LDFLAGS)

.PHONY	:	all clean fclean re