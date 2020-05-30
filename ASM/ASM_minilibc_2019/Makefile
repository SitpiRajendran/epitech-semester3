##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile compiles your programs
##

SRC =	src/strlen.asm	\
		src/memcpy.asm	\
		src/memmove.asm	\
		src/rindex.asm	\
		src/strchr.asm	\
		src/strstr.asm	\
		src/memset.asm	\
		src/strcasecmp.asm	\
		src/strcmp.asm	\
		src/strcspn.asm	\
		src/strncmp.asm	\
		src/strpbrk.asm	\

SRCTEST =	tests/strlen_test.c \
			tests/memcpy_test.c \
			tests/memmove_test.c \
			tests/rindex_test.c \
			tests/strchr_test.c \
			tests/strstr_test.c \

ASMFLAGS = -f elf64

CPPFLAGS = -fpic -shared

NAME = libasm.so

TEST_NAME = unit_test

OBJ = $(SRC:.asm=.o)

all: $(NAME)

%.o: %.asm
	nasm $(ASMFLAGS) $< -o $@

$(NAME): $(OBJ)
	@ld $(CPPFLAGS) -o $(NAME) $(OBJ)
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"

clean:
	@rm -f $(OBJ)
	@rm -f *.gcno
	@rm -f *.gcda

fclean: clean
	@rm -f $(NAME)
	@rm -f $(TEST_NAME)
	@echo -e "\033[1;32mCleaning finished !\033[0m"

re: fclean all

tests_run: ASMFLAGS += -DUNIT_TEST
tests_run: FLAGS += --coverage -lcriterion -L -lasm
tests_run: $(NAME)
	@gcc $(OBJ) $(SRCTEST) $(FLAGS) -o $(TEST_NAME)
	@rm -f $(OBJ)
	@echo -e "\033[1;32m Test Compilation completed sucessfully\033[0m"
	./$(TEST_NAME)

.PHONY: all clean fclean re tests_run

.SILENT: $(OBJ) $(OBJ_T)
