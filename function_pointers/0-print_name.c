#include "function_pointers.h"

/**
 * print_name - prints a name
 * @name: pointer to the name string
 * @f: function to print/format the name
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
	{
		f(name);
	}
}
