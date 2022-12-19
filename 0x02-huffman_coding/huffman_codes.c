#include "huffman.h"

/**
 * print_huffman - Print Huffman tree
 * @node: Is a Pointer to root of tree
 * @bin: Is a Binary number
 *
 * Return: Nothing
 */
void print_huffman(binary_tree_node_t *node, int bin)
{
	symbol_t *symbol = NULL;

	if (!node)
		return;
	symbol = node->data;
	if (symbol->data != -1)
		printf("%c: %s\n", symbol->data, itoa(bin, 2) + 1);
	else
	{
			print_huffman(node->left, bin << 1);
			print_huffman(node->right, (bin << 1) + 1);
	}
	free(symbol);
	free(node);
}

/**
 * huffman_codes - Build the Huffman tree and print the resulting Huffman
 * codes for each symbol
 * @data: Is an array of characters of size size
 * @freq: Is an array containing the associated frequencies (of size size too)
 * @size: Size of data
 *
 * Return: 1 if it succeed, 0 if it fails
 */
int huffman_codes(char *data, size_t *freq, size_t size)
{
	binary_tree_node_t *node = NULL;

	if (!data || !freq || !size)
		return (0);

	node = huffman_tree(data, freq, size);
	print_huffman(node, 1);
	return (1);
}
