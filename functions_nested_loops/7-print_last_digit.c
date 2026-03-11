#include "main.h"

/**
 * print_last_digit - prints and returns the last digit of a number
 * @n: number to process
 *
 * Return: last digit of n
 */
int print_last_digit(int n)
{
	int last;

	last = n % 10;

	if (last < 0)
		last = -last;

	_putchar('0' + last);

	return (last);
}

