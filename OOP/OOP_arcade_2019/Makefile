##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

RM	= rm -rf

all	:
		make -s -C ./src/lib/
		make -s -C ./src/core/
		mv ./src/core/arcade ./arcade
		make -s -C ./src/game/nibbler
		mv ./src/game/nibbler/lib_arcade_nibbler.so ./game/lib_arcade_nibbler.so

clean	:
		make clean -s -C ./src/core/
		make clean -s -C ./src/lib/
		make clean -s -C ./src/game/nibbler/

fclean	:	clean
		make fclean -s -C ./src/core/
		make fclean -s -C ./src/lib/
		make fclean -s -C ./src/game/nibbler/
		rm ./arcade
		rm ./game/lib_arcade_nibbler.so

re	:
		make re -s -C ./src/lib/
		make re -s -C ./src/core/
		make re -s -C ./src/game/nibbler
		mv ./src/core/arcade ./arcade
		mv ./src/game/nibbler/lib_arcade_nibbler.so ./game/lib_arcade_nibbler.so

.PHONY	:	all clean fclean re