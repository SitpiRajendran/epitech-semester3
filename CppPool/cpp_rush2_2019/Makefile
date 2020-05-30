##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Le Makefile de la lib
##

SRC =	tests/test.cpp  			\
		GiftPaper.cpp   			\
		Box.cpp		 				\
		LittlePony.cpp  			\
		Object.cpp      			\
		Teddy.cpp       			\
		Toy.cpp		 				\
		Wrap.cpp					\
		ConveyorBelt.cpp			\
		IConveyorBelt.cpp			\
		ITable.cpp					\
		PapaXmasConveyorBelt.cpp	\
		PapaXmasTable.cpp			\
		Table.cpp					\
		Hand.cpp

OBJ =   $(SRC:.c=.o)

CRIT = --coverage -lcriterion

WALL = -Wall -Wextra -Werror

CRITERION = unit_tests

tests_run:
			$(OBJ)
			g++ -o $(CRITERION) $(CRIT) $(OBJ)
			./$(CRITERION)

clean_test:	$(OBJ)
			g++ -o $(CRITERION) $(CRIT) $(OBJ)
			./$(CRITERION)
			gcovr
			rm -vf *.o
			rm -vf *.gcno
			rm -vf *.gcda
			rm $(CRITERION)

clean:
	rm -f *.o

fclean:
	rm -f *.o
	rm -f $(NAME)

re: fclean tests_run