CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g3 -I./
HEADER = nary_trees.h
BETTY = betty

SRC0 = 0-nary_tree_insert.c test/0-main.c
OBJ0 = $(patsubst %.c, obj/%.o, $(SRC0))
NAME0 = bin/0-nary_tree_insert

SRC1 = 1-nary_tree_delete.c 0-nary_tree_insert.c test/1-main.c
OBJ1 = $(patsubst %.c, obj/%.o, $(SRC1))
NAME1 = bin/1-nary_tree_delete

SRC2 = 2-nary_tree_traverse.c 1-nary_tree_delete.c 0-nary_tree_insert.c test/2-main.c
OBJ2 = $(patsubst %.c, obj/%.o, $(SRC2))
NAME2 = bin/2-nary_tree_traverse

SRC3 = 3-nary_tree_diameter.c 1-nary_tree_delete.c 0-nary_tree_insert.c test/3-main.c
OBJ3 = $(patsubst %.c, obj/%.o, $(SRC3))
NAME3 = bin/3-nary_tree_diameter

SRC4 = 4-path_exists.c 1-nary_tree_delete.c 0-nary_tree_insert.c test/4-main.c
OBJ4 = $(patsubst %.c, obj/%.o, $(SRC4))
NAME4 = bin/4-path_exists

ALLOBJ = $(OBJ0) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4)
ALLNAME = $(NAME0) $(NAME1) $(NAME2) $(NAME3) $(NAME4)

.PHONY: task0 task1 task2 task3 task4

all: task0 task1 task2 task3 task4

directories:
	mkdir -p obj bin obj/test

obj/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Task 0-4
task0: directories $(HEADER) $(OBJ0)
	$(CC) $(CFLAGS) $(OBJ0) -o $(NAME0)
	./$(NAME0)

task1: directories $(OBJ1)
	$(CC) $(CFLAGS) $(OBJ1) -o $(NAME1)
	valgrind ./$(NAME1)

task2: directories $(HEADER) $(OBJ2)
	$(CC) $(CFLAGS) $(OBJ2) -o $(NAME2)
	./$(NAME2)

task3: directories $(HEADER) $(OBJ3)
	$(CC) $(CFLAGS) $(OBJ3) -o $(NAME3)
	./$(NAME3)

task4: directories $(HEADER) $(OBJ4)
	$(CC) $(CFLAGS) $(OBJ4) -o $(NAME4)
	./$(NAME4)

clean:
	$(foreach var, $(ALLNAME), $(RM) *~ $(var))

oclean:
	$(foreach var, $(ALLOBJ), $(RM) $(var))

fclean: clean oclean

re: oclean all

betty:
	$(BETTY) *.c *.h test/*.c Makefile
