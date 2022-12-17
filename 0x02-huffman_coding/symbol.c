#include "huffman.h"

/**
 * symbol_create - Creates a symbol_t data structure
 * @data: Is the data to be stored in the structure
 * @freq: Is its associated frequencyI
 *
 * Return: A pointer to the created structure, or NULL if it fails
 */
symbol_t *symbol_create(char data, size_t freq)
{
	symbol_t *new = NULL;

	new = malloc(sizeof(symbol_t));
	if (new == NULL)
	{
		fprintf(stderr, "Can´t malloc\n");
		return (NULL);
	}
	new->data = data;
	new->freq = freq;

	return (new);
}
