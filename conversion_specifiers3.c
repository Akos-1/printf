#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - a function that produces output according to a format and handles
 * conversion specifiers.
 * @format: a character string.
 * Return:  the number of characters printed
 */
int _printf(const char *format, ...)
{
	int chars_displayed = 0;
	va_list argu;

	va_start(argu, format);

	while (*format)
	{
		char specifier = *format++;

		if (*format == '%')
		{
			format++;

			if (specifier == 'c')
				chars_displayed += write_char(va_arg(argu, int));
			else if (specifier == 's')
			{
				const char *str = va_arg(argu, const char *);

				while (*str)
				{
					chars_displayed += write_char(*str++);
				}
			}
			else if (specifier == 'd' || specifier == 'i' || specifier == 'u' ||
					specifier == 'o' || specifier == 'x' || specifier == 'X')
				chars_displayed += write_char(specifier);
			else if (specifier == '%')
				chars_displayed += write_char('%');
		}
		else
			chars_displayed += write_char(*format++);
	}

	va_end(argu);
	return (chars_displayed);
}

