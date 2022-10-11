# 0x00-red_black_tree

# Files

### 0. Red-Black - New node
### [0-rb_tree_node.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x00-red_black_tree/0-rb_tree_node.c)

```C
/**
 * enum rb_color_e - Possible color of a Red-Black tree
 *
 * @RED: 0 -> Red node
 * @BLACK: 1 -> Black node
 */
typedef enum rb_color_e
{
    RED = 0,
    BLACK,
    DOUBLE_BLACK
} rb_color_t;

/**
 * struct rb_tree_s - Red-Black tree node structure
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 * @color: Color of the node (RED or BLACK)
 */
typedef struct rb_tree_s
{
    int n;
    rb_color_t color;
    struct rb_tree_s *parent;
    struct rb_tree_s *left;
    struct rb_tree_s *right;
} rb_tree_t;

```

### 1. Red-Black - Is Red-Black
### [1-rb_tree_is_valid.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x00-red_black_tree/1-rb_tree_is_valid.c)

```C
alex@/tmp/huffman_rb_trees$ cat 0-main.c
#include <stdlib.h>
#include "rb_trees.h"

void rb_tree_print(const rb_tree_t *tree);

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    rb_tree_t *root;

    root = rb_tree_node(NULL, 98, BLACK);

    root->left = rb_tree_node(root, 12, RED);
    root->left->left = rb_tree_node(root->left, 6, BLACK);
    root->left->right = rb_tree_node(root->left, 16, BLACK);

    root->right = rb_tree_node(root, 402, RED);
    root->right->left = rb_tree_node(root->right, 256, BLACK);
    root->right->right = rb_tree_node(root->right, 512, BLACK);

    rb_tree_print(root);
    return (EXIT_SUCCESS);
}
alex@/tmp/huffman_rb_trees$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-rb_tree_node.c rb_tree_print.c -o rb_tree_node
alex@/tmp/huffman_rb_trees$ ./rb_tree_node
         .--------B(098)---------.
   .--R(012)---.           .--R(402)---.
B(006)      B(016)      B(256)      B(512)
alex@/tmp/huffman_rb_trees$

```

### 2. Red-Black - Insert
### [2-rb_tree_insert.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x00-red_black_tree/2-rb_tree_insert.c)

```C
alex@/tmp/huffman_rb_trees$ cat 1-main.c
#include <stdlib.h>
#include <stdio.h>
#include "rb_trees.h"

void rb_tree_print(const rb_tree_t *tree);

/**
 * valid_rb - Builds a valid R-B tree
 *
 * Return: A pointer to the created tree
 */
rb_tree_t *valid_rb(void)
{
    rb_tree_t *root;

    root = rb_tree_node(NULL, 98, BLACK);
    root->left = rb_tree_node(root, 90, BLACK);
    root->right = rb_tree_node(root, 120, BLACK);
    root->left->left = rb_tree_node(root->left, 79, RED);
    root->left->right = rb_tree_node(root->left, 95, RED);
    return (root);
}

/**
 * not_valid_rb - Builds a not valid R-B tree
 *
 * Return: A pointer to the created tree
 */
rb_tree_t *not_valid_rb(void)
{
    rb_tree_t *root;

    root = rb_tree_node(NULL, 98, BLACK);
    root->left = rb_tree_node(root, 90, RED);
    root->right = rb_tree_node(root, 120, RED);
    root->left->left = rb_tree_node(root->left, 79, BLACK);
    root->left->right = rb_tree_node(root->left, 95, BLACK);
    root->left->right->left = rb_tree_node(root->left->right, 92, RED);
    root->left->right->right = rb_tree_node(root->left->right, 96, RED);
    root->right->right = rb_tree_node(root->right, 130, BLACK);
    return (root);
}

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    rb_tree_t *root;
    int valid;

    root = valid_rb();
    rb_tree_print(root);
    valid = rb_tree_is_valid(root);
    printf("Is %d valid: %d\n", root->n, valid);

    root = not_valid_rb();
    rb_tree_print(root);
    valid = rb_tree_is_valid(root);
    printf("Is %d valid: %d\n", root->n, valid);

    root->color = RED;
    rb_tree_print(root);
    valid = rb_tree_is_valid(root);
    printf("Is %d valid: %d\n", root->n, valid);
    return (EXIT_SUCCESS);
}
alex@/tmp/huffman_rb_trees$ gcc -Wall -Wextra -Werror -pedantic 1-main.c 1-rb_tree_is_valid.c 0-rb_tree_node.c  rb_tree_print.c -o rb_tree_valid
alex@/tmp/huffman_rb_trees$ ./rb_tree_valid
         .--------B(098)---.
   .--B(090)---.        B(120)
R(079)      R(095)
Is 98 valid: 1
         .--------------------B(098)---.
   .--R(090)---------.              R(120)---.
B(079)         .--B(095)---.              B(130)
            R(092)      R(096)
Is 98 valid: 0
         .--------------------R(098)---.
   .--R(090)---------.              R(120)---.
B(079)         .--B(095)---.              B(130)
            R(092)      R(096)
Is 98 valid: 0
alex@/tmp/huffman_rb_trees$

```

### 3. Red-Black - Array to R-B Tree
### [3-array_to_rb_tree.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x00-red_black_tree/3-array_to_rb_tree.c)

```C
alex@/tmp/huffman_rb_trees$ cat 2-main.c
#include <stdlib.h>
#include <stdio.h>
#include "rb_trees.h"

void rb_tree_print(const rb_tree_t *tree);

/**
 * main - Entry point
 *
 * Return: 0 on success
 */
int main(void)
{
    rb_tree_t *root;
    rb_tree_t *node;

    root = NULL;
    node = rb_tree_insert(&root, 98);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 402);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 512);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 12);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 46);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 128);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 256);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 1);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 128);
    printf("Node should be nil -> %p\n", (void *)node);
    node = rb_tree_insert(&root, 624);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 780);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    return (0);
}
alex@/tmp/huffman_rb_trees$ gcc -Wall -Wextra -Werror -pedantic 2-main.c 0-rb_tree_node.c 2-rb_tree_insert.c rb_tree_print.c -o rb_tree_insert
alex@/tmp/huffman_rb_trees$ ./rb_tree_insert 
Inserted: 98
B(098)
Inserted: 402
B(098)---.
      R(402)
Inserted: 512
   .--B(402)---.
R(098)      R(512)
Inserted: 12
         .--B(402)---.
   .--B(098)      B(512)
R(012)
Inserted: 46
         .--------B(402)---.
   .--B(046)---.        B(512)
R(012)      R(098)
Inserted: 128
         .--------------B(402)---.
   .--R(046)---.              B(512)
B(012)      B(098)---.
                  R(128)
Inserted: 256
         .--------------------B(402)---.
   .--R(046)---------.              B(512)
B(012)         .--B(128)---.
            R(098)      R(256)
Inserted: 1
               .--------------------B(402)---.
         .--R(046)---------.              B(512)
   .--B(012)         .--B(128)---.
R(001)            R(098)      R(256)
Node should be nil -> (nil)
Inserted: 624
               .--------------------B(402)---.
         .--R(046)---------.              B(512)---.
   .--B(012)         .--B(128)---.              R(624)
R(001)            R(098)      R(256)
Inserted: 780
               .--------------------B(402)---------.
         .--R(046)---------.                 .--B(624)---.
   .--B(012)         .--B(128)---.        R(512)      R(780)
R(001)            R(098)      R(256)
alex@/tmp/huffman_rb_trees$

```

### 4. Red-Black - Remove
### [4-rb_tree_remove.c,](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x00-red_black_tree/4-rb_tree_remove.c,) | [0-rb_tree_node.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x00-red_black_tree/0-rb_tree_node.c)

```C
alex@/tmp/huffman_rb_trees$ cat 3-main.c
#include <stdlib.h>
#include "rb_trees.h"

void rb_tree_print(const rb_tree_t *tree);

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    rb_tree_t *tree;
    int array[] = {
        79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
        20, 22
    };
    size_t n = sizeof(array) / sizeof(array[0]);

    tree = array_to_rb_tree(array, n);
    if (!tree)
        return (1);
    rb_tree_print(tree);
    return (0);
}
alex@/tmp/huffman_rb_trees$ gcc -Wall -Wextra -Werror -pedantic 3-main.c 0-rb_tree_node.c 2-rb_tree_insert.c 3-array_to_rb_tree.c rb_tree_print.c -o rb_tree_array
alex@/tmp/huffman_rb_trees$ ./rb_tree_array
                           .--------------B(068)---------.
         .--------------B(032)---------.           .--B(084)---.
   .--R(020)---.                 .--B(047)      B(079)      B(087)---.
B(002)      B(021)---.        R(034)                              R(091)
                  R(022)
alex@/tmp/huffman_rb_trees$

```

### 5. Big O #Red-Black Tree
### [5-O](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x00-red_black_tree/5-O)

```C
alex@/tmp/huffman_rb_trees$ cat 3-main.c
#include <stdlib.h>
#include "rb_trees.h"

void rb_tree_print(const rb_tree_t *tree);

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    rb_tree_t *tree;
    int array[] = {
        79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
        20, 22
    };
    size_t n = sizeof(array) / sizeof(array[0]);

    tree = array_to_rb_tree(array, n);
    if (!tree)
        return (1);
    rb_tree_print(tree);
    return (0);
}
alex@/tmp/huffman_rb_trees$ gcc -Wall -Wextra -Werror -pedantic 3-main.c 0-rb_tree_node.c 2-rb_tree_insert.c 3-array_to_rb_tree.c rb_tree_print.c -o rb_tree_array
alex@/tmp/huffman_rb_trees$ ./rb_tree_array
                           .--------------B(068)---------.
         .--------------B(032)---------.           .--B(084)---.
   .--R(020)---.                 .--B(047)      B(079)      B(087)---.
B(002)      B(021)---.        R(034)                              R(091)
                  R(022)
alex@/tmp/huffman_rb_trees$

```

