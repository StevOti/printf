#include "main.h"

/**
* _strlen - function that gets the length of a string
* @s: String input
* Return: Int value length of string
*/

int _strlen(char *s)
{
	int len = 0;

	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}
