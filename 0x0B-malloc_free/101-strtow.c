#include <stdlib.h>
#include "main.h"

/**
 * count_word - helper function to count the number of words in a string
 * @s: string to evaluate
 * Return: number of words
 */
int count_word(char *s)
{
	int flag, c, w;

	flag = 0;
	w = 0;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			w++;
		}
	}

	return (w);
}

/**
 * allocate_matrix - allocates memory for the matrix
 * @words: number of words
 * Return: pointer to the allocated matrix
 */
char **allocate_matrix(int words)
{
	char **matrix;

	matrix = malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	return (matrix);
}

/**
 * copy_word - copies a word from the string to a new memory location
 * @start: starting index of the word
 * @end: ending index of the word
 * @str: string containing the words
 * Return: pointer to the copied word
 */
char *copy_word(int start, int end, char *str)
{
	char *word;
	int i, length = end - start;

	word = malloc(sizeof(char) * (length + 1));
	if (word == NULL)
		return (NULL);

	for (i = 0; start < end; i++, start++)
		word[i] = str[start];

	word[i] = '\0';

	return (word);
}

/**
 * fill_matrix - fills the matrix with words from the string
 * @matrix: matrix to fill
 * @str: string containing the words
 * @words: number of words
 */
void fill_matrix(char **matrix, char *str, int words)
{
	int i, k = 0, len = 0, c = 0, start, end;

	for (i = 0; str[i]; i++)
		len++;

	for (i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c)
			{
				end = i;
				matrix[k] = copy_word(start, end, str);
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}

	matrix[k] = NULL;
}

/**
 * strtow - splits a string into words
 * @str: string to split
 * Return: pointer to an array of strings (Success) or NULL (Error)
 */
char **strtow(char *str)
{
	char **matrix;
	int words;

	if (str == NULL || *str == '\0')
		return (NULL);

	words = count_word(str);

	if (words == 0)
		return (NULL);

	matrix = allocate_matrix(words);
	if (matrix == NULL)
		return (NULL);

	fill_matrix(matrix, str, words);

	return (matrix);
}
