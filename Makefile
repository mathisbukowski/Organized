##
## EPITECH PROJECT, 2023
## my_ls
## File description:
## Makefile
##
SRC = src/main.c\
		src/add_list.c\
		src/delete_list.c\
		src/display_list.c\
		src/shell_func.c\
		src/sort_list.c


SRC_UNIT = src/load_map.c\


FLAGS = -L./lib/my -lmy -L./lib -lshell

OBJ = $(SRC:.c=.o)

NAME = organized

CRI = --coverage -lcriterion

TEST_FILE = unit_tests

all: $(NAME)

$(NAME): $(OBJ)
		make -C lib/my
		make all -C lib/my
		make clean -C lib/my
		gcc $(SRC) -o $(NAME) -g $(FLAGS)
		make clean

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

tests_run: clean
		gcc -o $(TEST_FILE) $(SRC_UNIT) tests/test_organized.c $(FLAGS) $(CRI)
		./$(TEST_FILE) --verbose --full-stats

gcovr_branches:
		gcovr --exclude tests/ --branches
