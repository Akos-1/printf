#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <string.h>
#define BUFFER_SIZE 1024
/**
 * _printf - a function that displays output according to a format
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
				char arg = (char)va_arg(argu, int);

				write_char(arg, &chars_displayed);
			}
			else if (*format == 's')
			{
				char *str = va_arg(argu, char*);

				while (*str)
					write_char(*str++, &chars_displayed);
			}
			else if (strchr("diuoxXp", *format) == NULL)
			{
				write_char(*format, &chars_displayed);
				va_arg(argu, int);
			}
		}
		else
		{
			write_char(*format, &chars_displayed);
		}

		format++;
	}
	va_end(argu);
	return (chars_displayed);
}
