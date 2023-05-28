#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#define BUFFER_SIZE 1024
/**
 * write_buffer -  local buffer of 1024 chars in order to call write
 * @size: size of buffer
 * @count: count every character
 * @buffer: argument
 */
void write_buffer(const char *buffer, int size, int *count)
{
	int a;

	for (a = 0; a < size; a++)
	{
		write_char(buffer[a]);
	}
	(*count) += size;
}
/**
 * _printf - a function that displays output according to a format.
 * @format: a character string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int chars_displayed = 0;
	va_list argu;
	char buffer[BUFFER_SIZE];
	int buffer_index = 0;

	va_start(argu, format);

	while (*format)
	{
		char specifier = *format++;
		if (*format == '%')
		{
			format++;

			if (specifier == 'c')
				buffer[buffer_index++] = (char)va_arg(argu, int);
			else if (specifier == 's')
			{
				char *str = va_arg(argu, char*);

				while (*str)
					buffer[buffer_index++] = *str++;
			}
			else if (specifier == 'd' || specifier == 'i' || specifier == 'u' ||
					specifier == 'o' || specifier == 'x' || specifier == 'X')
				chars_displayed += printf("%%%c", specifier);
			else if (specifier == '%')
				buffer[buffer_index++] = '%';
		}
		else
			buffer[buffer_index++] = *format++;
		if (buffer_index == BUFFER_SIZE)
		{
			write_buffer(buffer, BUFFER_SIZE, &chars_displayed);
			buffer_index = 0;
		}
	}
	if (buffer_index > 0)
	{
		write_buffer(buffer, buffer_index, &chars_displayed);
	}
	va_end(argu);
	return (chars_displayed);
}
