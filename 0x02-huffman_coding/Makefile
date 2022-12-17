0:
	gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c test/0-main.c -o heap_create
	./heap_create
	rm heap_create

1:
	gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c test/1-main.c -o binary_tree_node
	./binary_tree_node
	rm binary_tree_node

2:
	gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c test/2-main.c binary_tree_print.c -o heap_insert
	./heap_insert
	rm heap_insert

3:
	gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c test/3-main.c binary_tree_print.c -o heap_extract
	./heap_extract
	rm heap_extract

4:
	gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c test/4-main.c binary_tree_print.c -o heap_delete
	valgrind ./heap_delete
	rm heap_delete

5:
	gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c test/5-main.c symbol.c -o symbol_create
	./symbol_create
	rm symbol_create

6:
	gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c test/6-main.c symbol.c huffman_priority_queue.c binary_tree_print.c -o prio
	./prio
	rm prio

betty:
	betty test/*.c heap/*.c *.h heap/*.h
