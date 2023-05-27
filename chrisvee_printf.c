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
	char present;

	va_list argu;

	va_start(argu, format);

	while ((present = *format++) != '\0')
	{
		if (new_char != '\0')
		{
			_putchar(present);
			chars_displayed++;
		}
		else
		{
			new_char = *format++;
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
						_putchar(*st++);
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
		}
	}
	va_end(argu);
	return (chars_displayed);
}
