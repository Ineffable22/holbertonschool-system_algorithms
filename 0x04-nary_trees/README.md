# 0x04-nary_trees

# Files

```C
/**
 * struct nary_tree_s - N-ary tree node structure
 *
 * @content: Content of the node
 * @parent: Pointer to the parent node
 * @nb_children: Number of children
 * @children: Pointer to the head node of the children linked list
 * @next: Pointer to the next child in the parent's children linked list
 */
typedef struct nary_tree_s
{
    char            *content;
    struct nary_tree_s  *parent;
    size_t          nb_children;
    struct nary_tree_s  *children;
    struct nary_tree_s  *next;
} nary_tree_t;

```

### 0. Insert
### [0-nary_tree_insert.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x04-nary_trees/0-nary_tree_insert.c)

```C
alex@ubuntu:~/0x04-nary_trees$ cat 0-main.c
#include <stdlib.h>
#include <stdio.h>

#include "nary_trees.h"

int main(void)
{
    nary_tree_t *root, *tmp, *var, *opt, *betty, *home, *alex;

    root = nary_tree_insert(NULL, "/");
    if (!root)
    {
        fprintf(stderr, "Failed to create node\n");
        return (EXIT_FAILURE);
    }

    tmp = nary_tree_insert(root, "tmp");
    nary_tree_insert(tmp, "tmp_file");

    var = nary_tree_insert(root, "var");
    nary_tree_insert(var, "www");

    opt = nary_tree_insert(root, "opt");
    betty = nary_tree_insert(opt, "Betty");
    nary_tree_insert(betty, "betty-style.pl");
    nary_tree_insert(betty, "betty-doc.pl");

    home = nary_tree_insert(root, "home");
    alex = nary_tree_insert(home, "alex");
    nary_tree_insert(alex, "Desktop");
    nary_tree_insert(alex, "Downloads");
    nary_tree_insert(alex, "Pictures");
    nary_tree_insert(alex, "Movies");
    nary_tree_insert(alex, "Documents");
    nary_tree_insert(alex, "Applications");

    return (EXIT_SUCCESS);
}
alex@ubuntu:~/0x04-nary_trees$ gcc -Wall -Wextra -Werror -pedantic -o 0-nary_tree_insert 0-nary_tree_insert.c 0-main.c
alex@ubuntu:~/0x04-nary_trees$ ./0-nary_tree_insert ; echo $?
0
alex@ubuntu:~/0x04-nary_trees$ 

```

### 1. Delete
### [1-nary_tree_delete.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x04-nary_trees/1-nary_tree_delete.c)

```C
alex@ubuntu:~/0x04-nary_trees$ cat 1-main.c
#include <stdlib.h>
#include <stdio.h>

#include "nary_trees.h"

int main(void)
{
    nary_tree_t *root, *tmp, *var, *opt, *betty, *home, *alex;

    root = nary_tree_insert(NULL, "/");
    if (!root)
    {
        fprintf(stderr, "Failed to create node\n");
        return (EXIT_FAILURE);
    }

    tmp = nary_tree_insert(root, "tmp");
    nary_tree_insert(tmp, "tmp_file");

    var = nary_tree_insert(root, "var");
    nary_tree_insert(var, "www");

    opt = nary_tree_insert(root, "opt");
    betty = nary_tree_insert(opt, "Betty");
    nary_tree_insert(betty, "betty-style.pl");
    nary_tree_insert(betty, "betty-doc.pl");

    home = nary_tree_insert(root, "home");
    alex = nary_tree_insert(home, "alex");
    nary_tree_insert(alex, "Desktop");
    nary_tree_insert(alex, "Downloads");
    nary_tree_insert(alex, "Pictures");
    nary_tree_insert(alex, "Movies");
    nary_tree_insert(alex, "Documents");
    nary_tree_insert(alex, "Applications");

    nary_tree_delete(root);

    return (EXIT_SUCCESS);
}
alex@ubuntu:~/0x04-nary_trees$ gcc -Wall -Wextra -Werror -pedantic -o 1-nary_tree_delete 1-nary_tree_delete.c 0-nary_tree_insert.c 1-main.c
alex@ubuntu:~/0x04-nary_trees$ valgrind ./1-nary_tree_delete
==26867== Memcheck, a memory error detector
==26867== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==26867== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==26867== Command: ./1-nary_tree_delete
==26867== 
==26867== 
==26867== HEAP SUMMARY:
==26867==     in use at exit: 0 bytes in 0 blocks
==26867==   total heap usage: X allocs, X frees, Y bytes allocated
==26867== 
==26867== All heap blocks were freed -- no leaks are possible
==26867== 
==26867== For counts of detected and suppressed errors, rerun with: -v
==26867== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
alex@ubuntu:~/0x04-nary_trees$ 

```

### 2. Traversal
### [2-nary_tree_traverse.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x04-nary_trees/2-nary_tree_traverse.c)

```C
alex@ubuntu:~/0x04-nary_trees$ cat 2-main.c
#include <stdlib.h>
#include <stdio.h>

#include "nary_trees.h"

void print_node(nary_tree_t const *node, size_t depth)
{
    printf("%*s%s\n", (int)depth * 2, "", node->content);
}

int main(void)
{
    nary_tree_t *root, *tmp, *var, *opt, *betty, *home, *alex;

    root = nary_tree_insert(NULL, "/");
    if (!root)
    {
        fprintf(stderr, "Failed to create node\n");
        return (EXIT_FAILURE);
    }

    tmp = nary_tree_insert(root, "tmp");
    nary_tree_insert(tmp, "tmp_file");

    var = nary_tree_insert(root, "var");
    nary_tree_insert(var, "www");

    opt = nary_tree_insert(root, "opt");
    betty = nary_tree_insert(opt, "Betty");
    nary_tree_insert(betty, "betty-style.pl");
    nary_tree_insert(betty, "betty-doc.pl");

    home = nary_tree_insert(root, "home");
    alex = nary_tree_insert(home, "alex");
    nary_tree_insert(alex, "Desktop");
    nary_tree_insert(alex, "Downloads");
    nary_tree_insert(alex, "Pictures");
    nary_tree_insert(alex, "Movies");
    nary_tree_insert(alex, "Documents");
    nary_tree_insert(alex, "Applications");

    nary_tree_traverse(root, &print_node);

    nary_tree_delete(root);

    return (EXIT_SUCCESS);
}
alex@ubuntu:~/0x04-nary_trees$ gcc -Wall -Wextra -Werror -pedantic -o 2-nary_tree_traverse 2-nary_tree_traverse.c 1-nary_tree_delete.c 0-nary_tree_insert.c 2-main.c
alex@ubuntu:~/0x04-nary_trees$ ./2-nary_tree_traverse
/
  home
    alex
      Applications
      Documents
      Movies
      Pictures
      Downloads
      Desktop
  opt
    Betty
      betty-doc.pl
      betty-style.pl
  var
    www
  tmp
    tmp_file
alex@ubuntu:~/0x04-nary_trees$ 

```

### 3. Diameter
### [3-nary_tree_diameter.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x04-nary_trees/3-nary_tree_diameter.c)

```C
alex@ubuntu:~/0x04-nary_trees$ cat 3-main.c
#include <stdlib.h>
#include <stdio.h>

#include "nary_trees.h"

void print_node(nary_tree_t const *node, size_t depth)
{
    printf("%*s%s\n", (int)depth * 2, "", node->content);
}

int main(void)
{
    nary_tree_t *root, *tmp, *var, *opt, *betty, *home, *alex;
    size_t diameter;

    root = nary_tree_insert(NULL, "/");
    if (!root)
    {
        fprintf(stderr, "Failed to create node\n");
        return (EXIT_FAILURE);
    }

    tmp = nary_tree_insert(root, "tmp");
    nary_tree_insert(tmp, "tmp_file");

    var = nary_tree_insert(root, "var");
    nary_tree_insert(var, "www");

    opt = nary_tree_insert(root, "opt");
    betty = nary_tree_insert(opt, "Betty");
    nary_tree_insert(betty, "betty-style.pl");
    nary_tree_insert(betty, "betty-doc.pl");

    home = nary_tree_insert(root, "home");
    alex = nary_tree_insert(home, "alex");
    nary_tree_insert(alex, "Desktop");
    nary_tree_insert(alex, "Downloads");
    nary_tree_insert(alex, "Pictures");
    nary_tree_insert(alex, "Movies");
    nary_tree_insert(alex, "Documents");
    nary_tree_insert(alex, "Applications");

    diameter = nary_tree_diameter(root);
    printf("Diameter = %lu\n", diameter);

    nary_tree_delete(root);

    return (EXIT_SUCCESS);
}
alex@ubuntu:~/0x04-nary_trees$ gcc -Wall -Wextra -Werror -pedantic -o 3-nary_tree_diameter 3-nary_tree_diameter.c 1-nary_tree_delete.c 0-nary_tree_insert.c 3-main.c
alex@ubuntu:~/0x04-nary_trees$ ./3-nary_tree_diameter
Diameter = 7
alex@ubuntu:~/0x04-nary_trees$ 

```

### 4. Path exists
### [4-path_exists.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x04-nary_trees/4-path_exists.c)

```C
alex@ubuntu:~/0x04-nary_trees$ cat 4-main.c
#include <stdlib.h>
#include <stdio.h>

#include "nary_trees.h"

void print_node(nary_tree_t const *node, size_t depth)
{
    printf("%*s%s\n", (int)depth * 2, "", node->content);
}

int main(void)
{
    nary_tree_t *root, *tmp, *var, *opt, *betty, *home, *alex;
    char const *path[] = {
        "/",
        "opt",
        "Betty",
        "betty-style.pl",
        NULL
    };
    char const *path2[] = {
        "/",
        "opt",
        "Betty",
        "betty-style.pl",
        "Holberton",
        NULL
    };

    root = nary_tree_insert(NULL, "/");
    if (!root)
    {
        fprintf(stderr, "Failed to create node\n");
        return (EXIT_FAILURE);
    }

    tmp = nary_tree_insert(root, "tmp");
    nary_tree_insert(tmp, "tmp_file");

    var = nary_tree_insert(root, "var");
    nary_tree_insert(var, "www");

    opt = nary_tree_insert(root, "opt");
    betty = nary_tree_insert(opt, "Betty");
    nary_tree_insert(betty, "betty-style.pl");
    nary_tree_insert(betty, "betty-doc.pl");

    home = nary_tree_insert(root, "home");
    alex = nary_tree_insert(home, "alex");
    nary_tree_insert(alex, "Desktop");
    nary_tree_insert(alex, "Downloads");
    nary_tree_insert(alex, "Pictures");
    nary_tree_insert(alex, "Movies");
    nary_tree_insert(alex, "Documents");
    nary_tree_insert(alex, "Applications");

    if (path_exists(root, (char const * const *)path))
        printf("Path exists!\n");
    else
        printf("Path does not exist\n");

    if (path_exists(root, (char const * const *)path2))
        printf("Path2 exists!\n");
    else
        printf("Path2 does not exist\n");

    nary_tree_delete(root);

    return (EXIT_SUCCESS);
}
alex@ubuntu:~/0x04-nary_trees$ gcc -Wall -Wextra -Werror -pedantic -o 4-path_exists 4-path_exists.c 1-nary_tree_delete.c 0-nary_tree_insert.c 4-main.c
alex@ubuntu:~/0x04-nary_trees$ ./4-path_exists
Path exists!
Path2 does not exist
alex@ubuntu:~/0x04-nary_trees$ 
```
