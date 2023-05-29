#include "main.h"
/**
 * handle_print - displays an argument based on its type
 * @frt: Formatted string
 * @argu: arguments list
 * @ind: ind.
 * @buffer: inputed Buffer array
 * @flg: active flags
 * @wid: width.
 * @pr: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *frt, int *ind, va_list argu, char buffer[],
	int flg, int wid, int pr, int size)
{
	int a, u_len = 0, displayed_chars = -1;
	funct frt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_per},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_oct}, {'x', print_hexadec},
		{'X', print_hexa_upp}, {'p', print_point}, {'S', print_non_printable},
		{'r', print_rev}, {'R', print_rot13str}, {'\0', NULL}
	};
	for (i = 0; frt_typ[i].frt != '\0'; i++)
		if (frt[*ind] == frt_typ[i].frt)
			return (frt_typ[i].fun(argu, buffer, flg, wid, pr, size));

	if (frt_typ[i].frt == '\0')
	{
		if (frt[*ind] == '\0')
			return (-1);
		u_len += write(1, "%%", 1);
		if (frt[*ind - 1] == ' ')
			u_len += write(1, " ", 1);
		else if (wid)
		{
			--(*ind);
			while (frt[*ind] != ' ' && frt[*ind] != '%')
				--(*ind);
			if (frt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		u_len += write(1, &frt[*ind], 1);
		return (u_len);
	}
	return (chars_displayed);
}
