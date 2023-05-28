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
				chars_displayed += write_char(va_arg(argu, int));
			else if (specifier == 'b')
				chars_displayed += print_binary(va_arg(argu, unsigned int));
			else if (specifier == '%')
				chars_displayed += write_char('%');
		}
		else
			chars_displayed += write_char(*format);
		format++;
	}
	va_end(argu);
	return (chars_displayed);
}
/**
 * print_binary - a function that converts unsigned int arguments to binary.
 * @num: nuber to be converted
 * Return: binaries.
 */

int print_binary(unsigned int num)
{
	int binary_dig[32];
	int y, x = 0;
	int chars_displayed = 0;

	if (num == 0)
	{
		write_char('0');
		return (1);
	}
	while (num > 0)
	{
		binary_dig[x++] = num % 2;
		num /= 2;
	}


	for (y = x - 1; y >= 0; y--)
	{
		write_char(binary_dig[y] + '0');
		chars_displayed++;
	}

	return (chars_displayed);
}

