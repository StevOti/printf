#include "main.h"
#include <stdlib.h>

void * print_integer(int n, int base)
{
	char *s;
	int len = 0, num, i, sign = 0;
	num = n;

	if (n < 0)
	{
		sign = 1;
		num *= -1;
		n *= -1;
	}
	while (n != 0)
	{
        	len++;
		n /= base;
	}

	s = malloc(sizeof(char) * len + 1);

	for (i = 1; i <= len; i++)
	{
		*(s + len - i) = num % 10 + '0';
		num /= base;
	}
	if (sign)
	{
		*--s = '-';
	}
	*(s + len + 1) ='\0';
	return(s);
}
