#include "huffman.h"

/**
 * write_huffman - Write Huffman tree in a file
 * @node: Is a Pointer to root of tree
 * @bin: Is a Binary number
 * @fd: File descriptor
 *
 * Return: Nothing
 */
void write_huffman(binary_tree_node_t *node, int bin, FILE *fd)
{
	symbol_t *symbol = NULL;

	if (!node)
		return;
	symbol = node->data;
	if (symbol->data != -1)
	{
		fwrite(&symbol->data, sizeof(int), 1, fd);
		fwrite(&bin, sizeof(int), 1, fd);
	}
	else
	{
		write_huffman(node->left, bin << 1, fd);
		write_huffman(node->right, (bin << 1) + 1, fd);
	}
	free(symbol);
	free(node);
}

/**
 * create_file - Create a file
 * @root: Pointer to root of binary tree
 * @out_filename: Name of file to write
 *
 * Return: Nothing
 */
void create_file(binary_tree_node_t *root, char *out_filename)
{
	FILE *fd;

	fd = fopen(out_filename, "wb+");
	if (fd == NULL)
	{
		fprintf(stderr, "%s can not be open\n", out_filename);
		return;
	}
	write_huffman(root, 1, fd);
	fclose(fd);
}

/**
 * read_huffman - read_huffman
 * @buffer: buffer
 * @size: size of data
 * @fd: File descriptor
 *
 * Return: Nothing
 */
void read_huffman(unsigned char *buffer, int size, FILE *fd)
{
	int i = 0;

	for (i = 0; i < size; i += 2)
	{
		fwrite(&buffer[i], sizeof(unsigned char), 1, fd);
		fwrite(&buffer[i + 1], sizeof(unsigned char), 1, fd);
	}
}

/**
 * decompress - decompress a file
 * @filename: Name of file to read
 * @out_filename: Name of file to write
 *
 * Return: -1 if failure, otherwise 0
 */
int decompress(char *filename, char *out_filename)
{
	FILE *fd = 0;
	int rd = 0;
	unsigned char buffer[BUFSIZ];
	binary_tree_node_t *root = NULL;

	printf("%s %s\n", filename, out_filename);
	fd = fopen(filename, "rb");
	if (fd == NULL)
	{
		fprintf(stderr, "%s can not be open\n", filename);
		return (-1);
	}
	rd = fread(buffer, sizeof(unsigned char), BUFSIZ, fd);
	if (rd == -1)
	{
		fprintf(stderr, "%s can not be read", filename);
		return (-1);
	}
	fclose(fd);
	read_huffman(buffer, rd, fd);
	(void) root;
	return (0);
}

/**
 * main - Compress and decompress a file
 * @argc: Argument number
 * @argv: Pointer to arguments
 *
 * Return: EXIT_FAILURE or EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
	int mode = checker(argc, argv);

	if (mode == 0)
		return (EXIT_FAILURE);
	if (mode == 1)
		compress(argv[2], argv[3]);
	else
		decompress(argv[2], argv[3]);
	return (EXIT_SUCCESS);
}
