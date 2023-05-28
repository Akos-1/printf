#include <stdio.h>
#include <stdarg.h>
#include "main.h"
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

			int p_flag = (*format == '+');
			int s_flag = (*format == ' ');

			if (p_flag || s_flag)
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
			else if (*format == 'd' || *format == 'i' || *format == 'u'
					|| *format == 'o' || *format == 'x' || *format == 'X' || *format == 'p')
			{
				if (plus_flag)
				{
					write_char('+');
					chars_displayed++;
				}
				else if (space_flag)
				{
					write_char(' ');
					chars_displayed++;
				}

				chars_displayed += printf("%", *format);
				va_arg(argu, int);
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
