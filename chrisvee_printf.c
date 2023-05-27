#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - a function that displays output according to a format.
 * @format: a character string.
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	int chars_displayed = 0;
	char present, arg, new_char, *st;
	va_list argu;

	va_start(argu, format);
	while ((present = *format++) != '\0')
	{
		if (new_char != '\0')
		{
			write_char(present);
			chars_displayed++;
		}
		else
		{
			new_char = *format++;

			if (new_char == 'c')
			{
				arg = (char)va_arg(argu, int);
				write_char(arg);
				chars_displayed++;
			}
			else if (new_char == 's')
			{
				st = va_arg(argu, char*);
				while (*st != '\0')
				{
					write_char(*st++);
					chars_displayed++;
				}
			}
			else if (new_char == '%')
			{
				write_char('%');
				chars_displayed++;
			}
		}
	}
	va_end(argu);
	return (chars_displayed);
}

