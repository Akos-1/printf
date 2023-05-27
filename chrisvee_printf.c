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
	char new_char;
	va_list argu;


	if (format == NULL)
		return (Error);

	va_start(argu, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			new_char = *format++;
			switch (new_char)
			{
				case 'c':
					int x = va_arg(argu, int);

					chars_displayed += write_char(x);
					break;
				case 's':
					char st = va_arg(argu, char);

					chars_displayed += fwrite(s, 1, strlen(s), stdout);
					break;
				case '%':
					chars_displayed += write_char('%');
					break;
			}
			else
			{
				chars_displayed += write_char(*format);
			}
		}
		format++;
	}
	va_end(argu);
	return (chars_displayed);
}

