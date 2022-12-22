#include "huffman.h"

/**
 * checker - Check validations
 * @argc: Argument number
 * @argv: Pointer to arguments
 *
 * Return: 1, 2 or 0 if fail
 */
int checker(int argc, char **argv)
{
	if (argc != 4 || strlen(argv[1]) != 1 ||
	    (*argv[1] != 'c' && *argv[1] != 'd'))
	{
		printf("%s <mode> <filename> <out_filename>\n", argv[0]);
		return (0);
	}

	if (access(argv[2], F_OK) == -1)
	{
		printf("No such file: %s\n", argv[2]);
		return (0);
	}
	if (access(argv[3], F_OK) != -1 && *argv[1] != 'd')
	{
		printf("File already exists: %s\n", argv[3]);
		return (0);
	}
	return (*argv[1] == 'c' ? 1 : 2);
}

/**
 * find_index - find index
 * @chr: char
 * @data: data store
 *
 * Return: index, otherwise -1
 */
int find_index(char chr, char *data)
{
	int i = 0;

	if (!data)
		return (-1);

	for (i = 0; data[i]; i++)
	{
		if (chr == data[i])
			return (i);
	}
	return (-1);
}

/**
 * create_arrays - Create array
 * @buffer: buffer
 * @data: data store
 * @freq: frequency of data
 * @size: size of data
 *
 * Return: lenght of data
 */
int create_arrays(unsigned char *buffer, char *data, size_t *freq, size_t size)
{
	size_t i = 0;
	int index = 0, len = 0;

	for (i = 0; i < size; i++)
	{
		index = find_index(buffer[i], data);
		if (index == -1)
		{
			len = strlen(data);
			data[len] = buffer[i];
			freq[len] = 1;
		}
		else
			freq[index] += 1;
	}
	return (strlen(data));
}

/**
 * create_huffman - Create a Huffman tree
 * @buffer: buffer
 * @size: size of data
 *
 * Return: A pointer to root
 */
binary_tree_node_t *create_huffman(unsigned char *buffer, int size)
{
	char *data = NULL;
	size_t *freq = NULL;
	binary_tree_node_t *root = NULL;

	data = calloc(sizeof(char), (size + 1));
	freq = calloc(sizeof(size_t), (size + 1));
	size = create_arrays(buffer, data, freq, size);
	root = huffman_tree(data, freq, size);
	return (root);
}

/**
 * compress - compress a file
 * @filename: Name of file to read
 * @out_filename: Name of file to write
 *
 * Return: -1 if failure, otherwise 0
 */
int compress(char *filename, char *out_filename)
{
	FILE *fd = 0;
	int rd = 0;
	unsigned char buffer[BUFSIZ];
	binary_tree_node_t *root = NULL;

	printf("%s %s\n", filename, out_filename);
	fd = fopen(filename, "r");
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
	printf("FILE => %s\n", buffer);
	root = create_huffman(buffer, rd);
	create_file(root, out_filename);
	return (0);
}
