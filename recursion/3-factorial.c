#include "main.h"

/**
 * factorial - returns the factorial of a given number
 * @n: number to compute
 *
 * Return: factorial of n, or -1 for negative n
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);

	if (n == 0)
		return (1);

	return (n * factorial(n - 1));
}
