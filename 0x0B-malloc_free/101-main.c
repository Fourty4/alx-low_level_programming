#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * print_tab - Prints an array of strings
 * @tab: The array to print
 *
 * Return: nothing
 */
void print_tab(char **tab)
{
	int i;

	for (i = 0; tab[i] != NULL; ++i)
	{
		printf("%s\n", tab[i]);
	}
}

/**
 * main - check the code for ALX School students.
 *
 * Return: 1 if an error occurred, 0 otherwise
 */
int main(void)
{
	char **tab;
	char *input = "      ALX School         #cisfun      ";
	int start = 0;
	int end = strlen(input) - 1;

	while (input[start] == ' ')
	{
		start++;
	}

	while (input[end] == ' ')
	{
		end--;
	}

	input = strndup(input + start, end - start + 1);

	tab = strtow(input);
	if (tab == NULL)
	{
		printf("Failed\n");
		return (1);
	}
	print_tab(tab);
	return (0);
}
