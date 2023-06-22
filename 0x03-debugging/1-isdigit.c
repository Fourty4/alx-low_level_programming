#include "main.h"

/**
 * _isdigit - check if Character is a digit
 * @x: The number to be checked
 *
 * Return: 0 or 1
 */

int _isdigit(int x)
{
	if (x >= 48 && x <= 57)
		return (1);
	else
		return (0);
}
