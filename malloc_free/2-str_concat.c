#include "main.h"
#include <stdlib.h>

/**
 * _strlen - returns the length of a string
 * @s: string to measure
 *
 * Return: length of the string
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
 * str_concat - concatenates two strings in newly allocated memory
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to concatenated string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *concat;
	unsigned int len1;
	unsigned int len2;
	unsigned int i;
	unsigned int j;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}

	len1 = _strlen(s1);
	len2 = _strlen(s2);

	concat = malloc(sizeof(char) * (len1 + len2 + 1));
	if (concat == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len1; i++)
	{
		concat[i] = s1[i];
	}

	for (j = 0; j < len2; j++)
	{
		concat[i + j] = s2[j];
	}
	concat[i + j] = '\0';

	return (concat);
}
