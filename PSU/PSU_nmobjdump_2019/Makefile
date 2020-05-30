##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile compiles your programs
##

SRC_NM	=	src/nm_main.c 	\
			src/nm_launch.c	\
			src/nm_sort.c

SRC_DUMP	= 	src/dump_main.c	\
				src/dump_header_32.c	\
				src/dump_header_64.c	\
				src/dump_s_64.c		\
				src/dump_s_32.c

OBJ_DUMP = $(SRC_DUMP:.c=.o)

OBJ_NM = $(SRC_NM:.c=.o)

CPPFLAGS = -I ./include -g3

NAME_DUMP = my_objdump

NAME_NM = my_nm

all: nm objdump

clean:
	@rm -f $(OBJ_NM) $(OBJ_DUMP)

nm : $(OBJ_NM)
	@$(CC) -o $(NAME_NM) $(OBJ_NM) $(CPPFLAGS)
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"
	@rm -f $(OBJ_NM)

objdump : $(OBJ_DUMP)
	@$(CC) -o $(NAME_DUMP) $(OBJ_DUMP) $(CPPFLAGS)
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"
	@rm -f $(OBJ_DUMP)

fclean: clean
	@rm -f $(NAME_DUMP) $(NAME_NM)
	@echo -e "\033[1;32mCleaning finished !\033[0m"

re: fclean all

.PHONY: all clean fclean re nm objdump

.SILENT: $(OBJ_DUMP) $(OBJ_NM)
