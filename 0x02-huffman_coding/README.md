# 0x02-huffman_coding

# Files

### 0. Min Binary Heap - Create heap
### [heap/heap_create.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x02-huffman_coding/heap/heap_create.c)

```C
/**
 * struct binary_tree_node_s - Binary tree node data structure
 *
 * @data: Data stored in a node
 * @left: Pointer to the left child
 * @right: Pointer to the right child
 * @parent: Pointer to the parent node
 */
typedef struct binary_tree_node_s
{
    void *data;
    struct binary_tree_node_s *left;
    struct binary_tree_node_s *right;
    struct binary_tree_node_s *parent;
} binary_tree_node_t;

/**
 * struct heap_s - Heap data structure
 *
 * @size: Size of the heap (number of nodes)
 * @data_cmp: Function to compare two nodes data
 * @root: Pointer to the root node of the heap
 */
typedef struct heap_s
{
    size_t size;
    int (*data_cmp)(void *, void *);
    binary_tree_node_t *root;
} heap_t;

```

### 1. Min Binary Heap - Create node
### [heap/binary_tree_node.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x02-huffman_coding/heap/binary_tree_node.c)

```C
/**
 * struct symbol_s - Stores a char and its associated frequency
 *
 * @data: The character
 * @freq: The associated frequency
 */
typedef struct symbol_s
{
    char data;
    size_t freq;
} symbol_t;

```

### 2. Min Binary Heap - Insert node
### [heap/heap_insert.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x02-huffman_coding/heap/heap_insert.c) | [heap/binary_tree_node.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x02-huffman_coding/heap/binary_tree_node.c) | [heap/heap_create.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x02-huffman_coding/heap/heap_create.c)

```C
alex@/tmp/huffman_coding$ cat 0-main.c
#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

/**
 * int_cmp - Compares two integers
 *
 * @p1: First pointer
 * @p2: Second pointer
 *
 * Return: Difference between the two strings
 */
int int_cmp(void *p1, void *p2)
{
    int *n1, *n2;

    n1 = (int *)p1;
    n2 = (int *)p2;
    return (*n1 - *n2);
}

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS
 */
int main(void)
{
    heap_t *heap;

    heap = heap_create(int_cmp);
    if (heap == NULL)
    {
        fprintf(stderr, "Failed to create the heap\n");
        return (EXIT_FAILURE);
    }
    printf("Heap size: %lu\n", heap->size);
    printf("Heap root: %p\n", (void *)heap->root);
    return (EXIT_SUCCESS);
}
alex@/tmp/huffman_coding$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 0-main.c -o heap_create
alex@/tmp/huffman_coding$ ./heap_create
Heap size: 0
Heap root: (nil)
alex@/tmp/huffman_coding$

```

### 3. Min Binary Heap - Extract
### [heap/heap_extract.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x02-huffman_coding/heap/heap_extract.c)

```C
alex@/tmp/huffman_coding$ cat 1-main.c
#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS
 */
int main(void)
{
    binary_tree_node_t *node;
    int n, n2;

    n = 5;
    n2 = 10;
    node = binary_tree_node(NULL, &n);
    if (node == NULL)
    {
        fprintf(stderr, "Failed to create a node\n");
        return (EXIT_FAILURE);
    }
    printf("Node(%p): data(%d) left(%p) right(%p) parent(%p)\n",
        (void *)node, *((int *)node->data), (void *)node->left,
        (void *)node->right, (void *)node->parent);

    node->left = binary_tree_node(node, &n2);
    if (node == NULL)
    {
        fprintf(stderr, "Failed to create a node\n");
        return (EXIT_FAILURE);
    }
    printf("Node(%p): data(%d) left(%p) right(%p) parent(%p)\n",
        (void *)node->left, *((int *)node->left->data), (void *)node->left->left,
        (void *)node->left->right, (void *)node->left->parent);

    return (EXIT_SUCCESS);
}
alex@/tmp/huffman_coding$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 1-main.c -o binary_tree_node
alex@/tmp/huffman_coding$ ./binary_tree_node
Node(0x17e9010): data(5) left((nil)) right((nil)) parent((nil))
Node(0x17e9040): data(10) left((nil)) right((nil)) parent(0x17e9010)
alex@/tmp/huffman_coding$

```

### 4. Min Binary Heap - Delete heap
### [heap/heap_delete.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x02-huffman_coding/heap/heap_delete.c)

```C
alex@/tmp/huffman_coding$ cat 2-main.c
#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

/**
 * int_cmp - Compares two integers
 *
 * @p1: First pointer
 * @p2: Second pointer
 *
 * Return: Difference between the two strings
 */
int int_cmp(void *p1, void *p2)
{
    int *n1, *n2;

    n1 = (int *)p1;
    n2 = (int *)p2;
    return (*n1 - *n2);
}

/**
 * print_int - Stores a string in a buffer
 *
 * @buffer: Buffer to store the string
 * @data: Pointer to the string
 *
 * Return: Number of bytes written in buffer
 */
int print_int(char *buffer, void *data)
{
    int *n;
    int length;

    n = (int *)data;
    length = sprintf(buffer, "(%03d)", *n);
    return (length);
}

void binary_tree_print(const binary_tree_node_t *root, int (*print_data)(char *, void *));

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS
 */
int main(void)
{
    heap_t *heap;
    int array[] = {
        34, 2, 45, 23, 76
    };
    size_t size = sizeof(array) / sizeof(array[0]);
    size_t i;
    binary_tree_node_t *node;

    heap = heap_create(int_cmp);
    if (heap == NULL)
    {
        fprintf(stderr, "Failed to create the heap\n");
        return (EXIT_FAILURE);
    }
    printf("Heap size: %lu\n", heap->size);
    printf("Heap root: %p\n", (void *)heap->root);

    for (i = 0; i < size; ++i)
    {
        node = heap_insert(heap, &(array[i]));
        if (node == NULL)
        {
            fprintf(stderr, "Failed to insert a node\n");
            return (EXIT_FAILURE);
        }
        binary_tree_print(heap->root, print_int);
        printf("\n");
    }
    printf("Heap size: %lu\n", heap->size);
    return (EXIT_SUCCESS);
}
alex@/tmp/huffman_coding$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 2-main.c binary_tree_print.c -o heap_insert
alex@/tmp/huffman_coding$ ./heap_insert
Heap size: 0
Heap root: (nil)
(034)

  .--(002)
(034)

  .--(002)--.
(034)     (045)

       .--(002)--.
  .--(023)     (045)
(034)

       .-------(002)--.
  .--(023)--.       (045)
(034)     (076)

Heap size: 5
alex@/tmp/huffman_coding$

```

### 5. Symbols: Create symbol
### [symbol.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x02-huffman_coding/symbol.c)

```C
alex@/tmp/huffman_coding$ cat 3-main.c
#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

/**
 * int_cmp - Compares two integers
 *
 * @p1: First pointer
 * @p2: Second pointer
 *
 * Return: Difference between the two strings
 */
int int_cmp(void *p1, void *p2)
{
    int *n1, *n2;

    n1 = (int *)p1;
    n2 = (int *)p2;
    return (*n1 - *n2);
}

/**
 * print_int - Stores a string in a buffer
 *
 * @buffer: Buffer to store the string
 * @data: Pointer to the string
 *
 * Return: Number of bytes written in buffer
 */
int print_int(char *buffer, void *data)
{
    int *n;
    int length;

    n = (int *)data;
    length = sprintf(buffer, "(%03d)", *n);
    return (length);
}

void binary_tree_print(const binary_tree_node_t *heap, int (*print_data)(char *, void *));

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS
 */
int main(void)
{
    heap_t *heap;
    int array[] = {
        34, 2, 45, 23, 76
    };
    size_t size = sizeof(array) / sizeof(array[0]);
    size_t i;
    binary_tree_node_t *node;
    int *extracted;

    heap = heap_create(int_cmp);
    if (heap == NULL)
    {
        fprintf(stderr, "Failed to create the heap\n");
        return (EXIT_FAILURE);
    }
    printf("Heap size: %lu\n", heap->size);
    printf("Heap root: %p\n", (void *)heap->root);

    for (i = 0; i < size; ++i)
    {
        node = heap_insert(heap, &(array[i]));
        if (node == NULL)
        {
            fprintf(stderr, "Failed to insert a node\n");
            return (EXIT_FAILURE);
        }
    }
    binary_tree_print(heap->root, print_int);
    printf("Heap size: %lu\n\n", heap->size);

    extracted = (int *)heap_extract(heap);
    printf("Extracted: %d\n", *extracted);
    binary_tree_print(heap->root, print_int);
    printf("Heap size: %lu\n", heap->size);
    return (EXIT_SUCCESS);
}
alex@/tmp/huffman_coding$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 3-main.c binary_tree_print.c -o heap_extract
alex@/tmp/huffman_coding$ ./heap_extract
Heap size: 0
Heap root: (nil)
       .-------(002)--.
  .--(023)--.       (045)
(034)     (076)
Heap size: 5

Extracted: 2
       .--(023)--.
  .--(034)     (045)
(076)
Heap size: 4
alex@/tmp/huffman_coding$

```

### 6. Huffman coding - Step 1: Priority queue
### [huffman_priority_queue.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x02-huffman_coding/huffman_priority_queue.c)

```C
alex@/tmp/huffman_coding$ cat 4-main.c
#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

/**
 * int_cmp - Compares two integers
 *
 * @p1: First pointer
 * @p2: Second pointer
 *
 * Return: Difference between the two strings
 */
int int_cmp(void *p1, void *p2)
{
    int *n1, *n2;

    n1 = (int *)p1;
    n2 = (int *)p2;
    return (*n1 - *n2);
}

/**
 * print_int - Stores a string in a buffer
 *
 * @buffer: Buffer to store the string
 * @data: Pointer to the string
 *
 * Return: Number of bytes written in buffer
 */
int print_int(char *buffer, void *data)
{
    int *n;
    int length;

    n = (int *)data;
    length = sprintf(buffer, "(%03d)", *n);
    return (length);
}

void binary_tree_print(const binary_tree_node_t *heap, int (*print_data)(char *, void *));

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS
 */
int main(void)
{
    heap_t *heap;
    int array[] = {
        34, 2, 45, 23, 76
    };
    size_t size = sizeof(array) / sizeof(array[0]);
    size_t i;
    binary_tree_node_t *node;

    heap = heap_create(int_cmp);
    if (heap == NULL)
    {
        fprintf(stderr, "Failed to create the heap\n");
        return (EXIT_FAILURE);
    }
    printf("Heap size: %lu\n", heap->size);
    printf("Heap root: %p\n", (void *)heap->root);

    for (i = 0; i < size; ++i)
    {
        node = heap_insert(heap, &(array[i]));
        if (node == NULL)
        {
            fprintf(stderr, "Failed to insert a node\n");
            return (EXIT_FAILURE);
        }
        binary_tree_print(heap->root, print_int);
        printf("\n");
    }
    printf("Heap size: %lu\n", heap->size);
    heap_delete(heap, NULL);
    return (EXIT_SUCCESS);
}
alex@/tmp/huffman_coding$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 4-main.c binary_tree_print.c -o heap_delete
alex@/tmp/huffman_coding$ valgrind ./heap_delete
==102349== Memcheck, a memory error detector
==102349== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==102349== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==102349== Command: ./heap_delete
==102349== 
Heap size: 0
Heap root: (nil)
(034)

  .--(002)
(034)

  .--(002)--.
(034)     (045)

       .--(002)--.
  .--(023)     (045)
(034)

       .-------(002)--.
  .--(023)--.       (045)
(034)     (076)

Heap size: 5
==102349== 
==102349== HEAP SUMMARY:
==102349==     in use at exit: 0 bytes in 0 blocks
==102349==   total heap usage: 36 allocs, 36 frees, 3,373 bytes allocated
==102349== 
==102349== All heap blocks were freed -- no leaks are possible
==102349== 
==102349== For counts of detected and suppressed errors, rerun with: -v
==102349== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
alex@/tmp/huffman_coding$

```

### 7. Huffman coding - Step 2: Extract
### [huffman_extract_and_insert.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x02-huffman_coding/huffman_extract_and_insert.c)

```C
alex@/tmp/huffman_coding$ cat 5-main.c
#include <stdlib.h>
#include <stdio.h>
#include "huffman.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS
 */
int main(void)
{
    symbol_t *symbol;

    symbol = symbol_create('d', 3);
    if (symbol == NULL)
    {
        fprintf(stderr, "Failed to create a symbol\n");
        return (EXIT_FAILURE);
    }
    printf("Symbol: data(%c) frequency(%lu)\n", symbol->data, symbol->freq);

    symbol = symbol_create('H', 98);
    if (symbol == NULL)
    {
        fprintf(stderr, "Failed to create a symbol\n");
        return (EXIT_FAILURE);
    }
    printf("Symbol: data(%c) frequency(%lu)\n", symbol->data, symbol->freq);

    return (EXIT_SUCCESS);
}
alex@/tmp/huffman_coding$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 5-main.c symbol.c -o symbol_create
alex@/tmp/huffman_coding$ ./symbol_create
Symbol: data(d) frequency(3)
Symbol: data(H) frequency(98)
alex@/tmp/huffman_coding$

```

### 8. Huffman coding - Step 3: Build Huffman tree
### [huffman_tree.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x02-huffman_coding/huffman_tree.c)

```C
alex@/tmp/huffman_coding$ cat 6-main.c 
#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#include "huffman.h"

void binary_tree_print(const binary_tree_node_t *heap, int (*print_data)(char *, void *));

/**
 * nested_print - Prints a symbol structure stored in a nested node
 *
 * @buffer: Buffer to print into
 * @data: Pointer to a node's data
 *
 * Return: Number of bytes written in buffer
 */
int nested_print(char *buffer, void *data)
{
    binary_tree_node_t *nested;
    symbol_t *symbol;
    int length;

    nested = (binary_tree_node_t *)data;
    symbol = (symbol_t *)nested->data;
    length = sprintf(buffer, "(%c/%lu)", symbol->data, symbol->freq);
    return (length);
}

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    heap_t *priority_queue;
    char data[] = {
        'a', 'b', 'c', 'd', 'e', 'f'
    };
    size_t freq[] = {
        6, 11, 12, 13, 16, 36
    };
    size_t size = sizeof(data) / sizeof(data[0]);

    priority_queue = huffman_priority_queue(data, freq, size);
    if (!priority_queue)
    {
        fprintf(stderr, "Failed to create priority queue\n");
        return (EXIT_FAILURE);
    }
    binary_tree_print(priority_queue->root, nested_print);

    return (EXIT_SUCCESS);
}
alex@/tmp/huffman_coding$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 6-main.c symbol.c huffman_priority_queue.c binary_tree_print.c -o prio
alex@/tmp/huffman_coding$ ./prio
         .--------(a/6)---------.
   .--(b/11)---.          .--(c/12)
(d/13)      (e/16)     (f/36)
alex@/tmp/huffman_coding$

```

### 9. Huffman coding - Step 4: Huffman codes
### [huffman_codes.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x02-huffman_coding/huffman_codes.c)

```C
alex@/tmp/huffman_coding$ cat 7-main.c 
#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#include "huffman.h"

void binary_tree_print(const binary_tree_node_t *heap, int (*print_data)(char *, void *));

/**
 * nested_print - Prints a symbol structure stored in a nested node
 *
 * @buffer: Buffer to print into
 * @data: Pointer to a node's data
 *
 * Return: Number of bytes written in buffer
 */
int nested_print(char *buffer, void *data)
{
    binary_tree_node_t *nested;
    symbol_t *symbol;
    char c;
    int length;

    nested = (binary_tree_node_t *)data;
    symbol = (symbol_t *)nested->data;
    c = symbol->data;
    if (c == -1)
        c = '$';
    length = sprintf(buffer, "(%c/%lu)", c, symbol->freq);
    return (length);
}

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    heap_t *priority_queue;
    char data[] = {
        'a', 'b', 'c', 'd', 'e', 'f'
    };
    size_t freq[] = {
        6, 11, 12, 13, 16, 36
    };
    size_t size = sizeof(data) / sizeof(data[0]);

    priority_queue = huffman_priority_queue(data, freq, size);
    if (!priority_queue)
    {
        fprintf(stderr, "Failed to create priority queue\n");
        return (EXIT_FAILURE);
    }
    binary_tree_print(priority_queue->root, nested_print);
    printf("\n");

    huffman_extract_and_insert(priority_queue);
    binary_tree_print(priority_queue->root, nested_print);
    printf("\n");

    huffman_extract_and_insert(priority_queue);
    binary_tree_print(priority_queue->root, nested_print);

    return (EXIT_SUCCESS);
}
alex@/tmp/huffman_coding$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 7-main.c symbol.c huffman_priority_queue.c huffman_extract_and_insert.c binary_tree_print.c -o extract
alex@/tmp/huffman_coding$ ./extract
         .--------(a/6)---------.
   .--(b/11)---.          .--(c/12)
(d/13)      (e/16)     (f/36)

         .--------(c/12)---.
   .--(d/13)---.        (e/16)
(f/36)      ($/17)

         .--(e/16)---.
   .--($/17)      (f/36)
($/25)
alex@/tmp/huffman_coding$

```

### 10. Huffman - Compression & Decompression
### [huffman/Makefile](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x02-huffman_coding/huffman/Makefile)

```C
alex@/tmp/huffman_coding$ cat 8-main.c
#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#include "huffman.h"

void binary_tree_print(const binary_tree_node_t *heap, int (*print_data)(char *, void *));

/**
 * symbol_print - Prints a symbol structure
 *
 * @buffer: Buffer to print into
 * @data: Pointer to a node's data
 *
 * Return: Number of bytes written in buffer
 */
int symbol_print(char *buffer, void *data)
{
    symbol_t *symbol;
    char c;
    int length;

    symbol = (symbol_t *)data;
    c = symbol->data;
    if (c == -1)
        c = '$';
    length = sprintf(buffer, "(%c/%lu)", c, symbol->freq);
    return (length);
}

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    binary_tree_node_t *root;
    char data[] = {
        'a', 'b', 'c', 'd', 'e', 'f'
    };
    size_t freq[] = {
        6, 11, 12, 13, 16, 36
    };
    size_t size = sizeof(data) / sizeof(data[0]);

    root = huffman_tree(data, freq, size);
    if (!root)
    {
        fprintf(stderr, "Failed to build Huffman tree\n");
        return (EXIT_FAILURE);
    }
    binary_tree_print(root, symbol_print);

    return (EXIT_SUCCESS);
}
alex@/tmp/huffman_coding$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 8-main.c symbol.c huffman_priority_queue.c huffman_extract_and_insert.c huffman_tree.c binary_tree_print.c -o huffman_tree
alex@/tmp/huffman_coding$ ./huffman_tree
   .--($/94)---------------------.
(f/36)               .--------($/58)---------.
               .--($/25)---.           .--($/33)--------.
            (c/12)      (d/13)      (e/16)        .--($/17)---.
                                                (a/6)      (b/11)
alex@/tmp/huffman_coding$

```

