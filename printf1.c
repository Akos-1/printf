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
			char specifier = *(++format);

			if (specifier == 'c')
				chars_displayed += write_char((char)va_arg(argu, int));
			else if (specifier == 's')
				while (write_char(*(char *)va_arg(argu, char *)))
					chars_displayed++;
			else if (specifier == 'd' || specifier == 'i')
				chars_displayed += printf("%d", va_arg(argu, int));
			else if (specifier == '%')
				chars_displayed += write_char('%');
			else
				chars_displayed += write_char(*format);
		}
		else
			chars_displayed += write_char(*format);
		format++;
	}
	va_end(argu);
	return (chars_displayed);
}
