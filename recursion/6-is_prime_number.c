#include "main.h"

int is_prime_helper(int n, int divisor);

/**
 * is_prime_number - checks if a number is prime
 * @n: number to check
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);

	return (is_prime_helper(n, 2));
}

/**
 * is_prime_helper - checks divisibility using recursion
 * @n: number to check
 * @divisor: current divisor
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_helper(int n, int divisor)
{
	if (divisor > n / divisor)
		return (1);

	if (n % divisor == 0)
		return (0);

	return (is_prime_helper(n, divisor + 1));
}
