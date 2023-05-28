#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - a function that displays output according to a format.
 * @format: a character string
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	int chars_displayed = 0;
	char present;

	va_list argu;

	va_start(argu, format);
	while ((present = *format++) != '\0')
	{
		if (present == '%')
		{
			char specifier = *format++;

			if (specifier == 'c')
			{
				char arg = (char)va_argu(argu, int);

				write_char(arg);
				chars_displayed++;
			}
			else if (specifier == 's')
			{
				char *st = va_arg(argu, char*);
				
				while (*st != '\0')
				{
					write_char(*st++);
					chars_displayed++
				}
			}
			else if (specifier == 'd' || specifier == 'i')
			{
				int arg = va_arg(argu, int);

				chars_displayed += printf("%d", arg);
			}
			else if (specifier == '%')
			{
				write_char('%);
				chars_displayed++;
			}
			else
			{
				write_char(present);
				chars_displayed++;
			}
		}
	}
	va_end(argu);
	return chars_displayed;
}


