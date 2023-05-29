#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <unistd.h>
/**
 * _printf - a function that displays output according to a format.
 * @format: a character string
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	int chars_displayed = 0;
	va_list argu;

	va_start(argu, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'c' || *format == '%')
			{
				write_char((char)va_arg(argu, int));
				chars_displayed++;
			}
			else if (*format == 's')
			{
				char *st = va_arg(argu, char*);

				while (*st)
				{
					write_char(*st++);
					chars_displayed++;
				}
			}
			else if (strchr("diuoxXp", *format) != NULL)
			{
				if (*format == '+' || *format == ' ')
				{
					write_char(*format);
					chars_displayed++;
				}
				else
				{
				chars_displayed += write_char(va_arg(argu, int));
				}
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
