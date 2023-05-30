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
	int a, u_len = 0, chars_displayed = -1;
	funct frt_typ[] = {
		{'c', print_char}, {'s', print_str}, {'%', print_per},
		{'i', print_int}, {'d', print_int}, {'b', print_bin},
		{'u', print_unsgnd}, {'o', print_oct}, {'x', print_hexadec},
		{'X', print_hexa_upp}, {'p', print_point}, {'S', print_non_printable},
		{'r', print_rev}, {'R', print_rot13str}, {'\0', NULL}
	};
	for (a = 0; frt_typ[a].fr_t != '\0'; a++)
		if (frt[*ind] == frt_typ[a].fr_t)
			return (frt_typ[a].funct(argu, buffer, flg, wid, pr, size));

	if (frt_typ[a].fr_t == '\0')
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
