CC = gcc -g -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c *.c test/

all:
	$(CC)$(NUM)-main.c

run: all
	./a.out
	rm a.out

gdb: all
	gdb ./a.out

valgrind: all
	valgrind ./a.out
	rm ./a.out

betty:
	betty *.c test/*.c heap/*.c *.h heap/*.h

clean:
	rm a.out
