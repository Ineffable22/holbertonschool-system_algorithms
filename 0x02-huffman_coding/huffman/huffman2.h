#ifndef _HUFFMAN2_H_
#define _HUFFMAN2_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int checker(int argc, char **argv);
int find_index(char chr, char *data);
int create_arrays(unsigned char *buffer, char *data, size_t *freq, size_t size);
binary_tree_node_t *create_huffman(unsigned char *buffer, int size);
int compress(char *filename, char *out_filename);
void write_huffman(binary_tree_node_t *node, int bin, FILE *fd);
void create_file(binary_tree_node_t *root, char *out_filename);

#endif /* _HUFFMAN_H2_ */
