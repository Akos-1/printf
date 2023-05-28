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
				chars_displayed += putchar((char)va_arg(argu, int));
			else if (specifier == 's')
				while (putchar(*(char *)va_arg(argu, char *)))
					chars_displayed++;
			else if (specifier == 'd' || specifier == 'i' || specifier == 'u' ||
					specifier == 'o' || specifier == 'x' || specifier == 'X')
				chars_displayed += printf("%%%c", specifier);
			else if (specifier == '%')
				chars_displayed += putchar('%');
		}
		else
			chars_displayed += putchar(*format++);
	}

	va_end(argu);
	return (chars_displayed);
}

