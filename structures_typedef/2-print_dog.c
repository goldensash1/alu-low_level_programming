#include "dog.h"
#include <stdio.h>

/**
 * print_dog - prints a struct dog
 * @d: pointer to struct dog to print
 */
void print_dog(struct dog *d)
{
	char *name;
	char *owner;

	if (d == NULL)
	{
		return;
	}

	name = d->name;
	owner = d->owner;

	if (name == NULL)
	{
		name = "(nil)";
	}
	if (owner == NULL)
	{
		owner = "(nil)";
	}

	printf("Name: %s\n", name);
	printf("Age: %f\n", d->age);
	printf("Owner: %s\n", owner);
}
