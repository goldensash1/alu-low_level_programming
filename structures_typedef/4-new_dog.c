#include "dog.h"
#include <stdlib.h>

/**
 * _strlen - computes string length
 * @s: string
 *
 * Return: length of string
 */
static unsigned int _strlen(char *s)
{
	unsigned int len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}

	return (len);
}

/**
 * _strcpy - copies one string into another
 * @dest: destination buffer
 * @src: source string
 *
 * Return: pointer to destination buffer
 */
static char *_strcpy(char *dest, char *src)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * new_dog - creates a new dog
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 *
 * Return: pointer to newly created dog, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new;
	unsigned int name_len;
	unsigned int owner_len;

	if (name == NULL || owner == NULL)
	{
		return (NULL);
	}

	new = malloc(sizeof(dog_t));
	if (new == NULL)
	{
		return (NULL);
	}

	name_len = _strlen(name);
	owner_len = _strlen(owner);

	new->name = malloc(sizeof(char) * (name_len + 1));
	if (new->name == NULL)
	{
		free(new);
		return (NULL);
	}

	new->owner = malloc(sizeof(char) * (owner_len + 1));
	if (new->owner == NULL)
	{
		free(new->name);
		free(new);
		return (NULL);
	}

	_strcpy(new->name, name);
	_strcpy(new->owner, owner);
	new->age = age;

	return (new);
}
