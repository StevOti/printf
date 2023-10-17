#include "main.h"

/**
 * _putchar - This writes the character c to stdout
 * @c: This is the character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and error number is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
