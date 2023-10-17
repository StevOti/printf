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
	int ival;
	unsigned int uval = 0, uval_len = 0, uval_2 = 0;

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
				case 'd':
					ival = va_arg(char_list, int);
					char_count += write(1, print_int(ival, 10), _strlen(print_int(ival, 10)));
					break;
				case 'i':
					ival = va_arg(char_list, int);
					char_count += write(1, print_int(ival, 10), _strlen(print_int(ival, 10)));
					break;
				case 'u':
					ival = va_arg(char_list, int);
					char_count += write(1, print_int(ival, 10), _strlen(print_int(ival, 10)));
					break;
				case 'o':
					ival = va_arg(char_list, int);
					char_count += write(1, print_int(ival, 8), _strlen(print_int(ival, 8)));
					break;

				case 'b':
					uval = va_arg(char_list, unsigned int);
					ival = 0;
					uval_2 = uval;
					while (uval_2 >= 2)
					{
						uval_2 = uval_2 >> 1;
						uval_len++;
					}
					for (ival = (int)uval_len; ival >= 0; ival--)
					{
						c = uval & (1u << ival) ? '1' : '0';
						char_count += write(1, &c, 1);
					}
					break;
				case '%':
					c = '%';
					char_count += write(1, &c, 1);
					break;	
				default:
					char_count += write(1, --format, 1);
					char_count += write(1, ++format, 1);
					break;
			}
		}
	}
	va_end(char_list);
	return (char_count);
}
