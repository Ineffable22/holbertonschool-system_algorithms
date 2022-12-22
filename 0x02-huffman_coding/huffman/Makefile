CC = gcc -g -Wall -Wextra -Werror -pedantic -I./ -I../ -I../heap ../heap/*.c ../*.c *.c -o
NAME = huffman
C = c
DC = d
FILENAME = text.txt
OUT_FILENAME = file_compressed
NEW_FILENAME = new_text.txt

all:
	$(CC) $(NAME)

runc: all
	./$(NAME) $(C) $(FILENAME) $(OUT_FILENAME)

rund: all
	./$(NAME) $(DC) $(OUT_FILENAME) $(NEW_FILENAME)

gdbc: all
	gdb --args ./$(NAME) $(C) $(FILENAME) $(OUT_FILENAME)

gdbd: all
	gdb --args ./$(NAME) $(D) $(FILENAME) $(OUT_FILENAME)

valgrind: all
	valgrind ./$(NAME)
	rm ./$(NAME)

betty:
	betty *.c

clean:
	rm $(NAME)
