#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * _printf - function that produces an output according to a specified format
 * @format: string input
 * Return: number of characters printed
 */

int  _printf(const char *format, ...)
{
	va_list char_list;
	char *str_arg, c;
	int char_count = 0;

	va_start(char_list, format);
	for (; *format; format++)
	{
		if (*format != '%')
		{
			char_count += write(1, format, 1);
		} else
		{
			switch (*++format)
			{
				case 's':
					str_arg = va_arg(char_list, char *);
					char_count += write(1, str_arg, _strlen(str_arg));
					break;
				case 'c':
					c = (char)va_arg(char_list, int);
					char_count += write(1, &c, 1);
					break;
				default:
					break;
			}
		}
	}
	va_end(char_list);
	return (char_count);
}