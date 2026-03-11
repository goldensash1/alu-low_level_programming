#include "main.h"

int sqrt_helper(int n, int guess);

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to compute
 *
 * Return: natural square root, or -1 when none exists
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	if (n == 0 || n == 1)
		return (n);

	return (sqrt_helper(n, 1));
}

/**
 * sqrt_helper - finds the square root using recursive guesses
 * @n: number to compute
 * @guess: current guess
 *
 * Return: square root, or -1 when none exists
 */
int sqrt_helper(int n, int guess)
{
	if (guess > n / guess)
		return (-1);

	if (guess * guess == n)
		return (guess);

	return (sqrt_helper(n, guess + 1));
}
