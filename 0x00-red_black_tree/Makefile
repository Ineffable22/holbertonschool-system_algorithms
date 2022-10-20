0:
	cp files/0-main.c .
	gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-rb_tree_node.c rb_tree_print.c -o rb_tree_node
	rm 0-main.c
	./rb_tree_node
	rm rb_tree_node

1:
	cp files/1-main.c .
	gcc -Wall -Wextra -Werror -pedantic 1-main.c 1-rb_tree_is_valid.c 0-rb_tree_node.c  rb_tree_print.c -o rb_tree_valid
	rm 1-main.c
	./rb_tree_valid
	rm rb_tree_valid

2:
	cp files/2-main.c .
	gcc -Wall -Wextra -Werror -pedantic 2-main.c 0-rb_tree_node.c 2-rb_tree_insert.c rb_tree_print.c -o rb_tree_insert
	rm 2-main.c
	./rb_tree_insert
	rm rb_tree_insert

betty:
	betty files/*.c *.c *.h
