##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

CXX		=	g++

NAME	=	lib_arcade_nibbler.so

SRC		=	nibbler.cpp

OBJ		=	$(SRC:.cpp=.o)

CPPFLAGS	=  	-I./../../../include/nibbler

CXXFLAGS 	= 	-shared -fPIC -std=c++11

LDFLAGS		=

RM		=	rm -rf

all		:	$(NAME)

$(NAME) : $(OBJ)
		$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS) $(CPPFLAGS)

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