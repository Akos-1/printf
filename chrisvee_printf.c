#include <stdio.h>
#include "main.h"
/**
 * _printf - a function that displays output according to a format.
 * @format: a character string.
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	int chars_displayed = 0;
	char present, arg, new_char, *st = 0;
	va_list argu;

	va_start(argu, format);
	while (*format)
	{
		if (*format == '%' && *(++format))
		{
			if (*format == 'c')
			{
				write_char(va_arg(argu, int));
				chars_displayed++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(argu, char*);

				while (*str)
				{
					write_char(*str++);
					chars_displayed++;
				}
			}
			else if (*format == '%')
			{
				write_char('%');
				chars_displayed++;
			}
		}
		else
		{
			write_char(*format);
			chars_displayed++;
		}
		format++;
	}
	va_end(argu);
	return (chars_displayed);
}
