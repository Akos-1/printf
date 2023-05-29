#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int a, displayed = 0, chars_displayed = 0;
	int flg, wid, pr, size, buff_ind = 0;
	va_list argu;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(argu, format);

	for (a = 0; format && format[a] != '\0'; i++)
	{
		if (format[a] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFFER_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[a], 1);*/
			chars_displayed++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flg = get_flg(format, &a);
			wid = get_wid(format, &a, argu);
			pr = get_pr(format, &a, argu);
			size = get_size(format, &a);
			++a;
			displayed = handle_print(format, &a, argu, buffer,
					flg, wid, pr, size);
			if (displayed == -1)
				return (-1);
			chars_displayed += displayed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(argu);

	return (chars_displayed);
}

/**
 * print_buffer - diplays the contents 
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
