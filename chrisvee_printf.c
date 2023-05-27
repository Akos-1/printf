#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf -  a function that displays output according to a format.
 * @format:  a character string.
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int chars_displayed = 0;
	char arg, new_char, *st;
	va_list argu;

	va_start(argu, format);
	while (*format != '\0')
	{
		new_char = *format;
		switch (new_char)
		{
			case 'c':
				arg = (char)va_arg(argu, int);
				_putchar(arg);
				chars_displayed++;
				break;
			case 's':
				st = va_arg(argu, char*);
				while (*st != '\0')
				{
					chars_displayed++;
				}
				break;
			case '%':
				_putchar('%');
				chars_displayed++;
				break;
			default:
				break;
		}
		format++;
	}

	va_end(argu);
	return (chars_displayed);
}
