#include "main.h"
/**
 * print_point - displays a pointer variable value
 * @typ: arguments list
 * @buffer: inputed Buffer array
 * @flg: active flags
 * @wid: get width
 * @pr: Precision specification
 * @size: Size specifier
 * Return: Number of chars displayed.
 */
int print_point(va_list typ, char buffer[],
		int flg, int wid, int pr, int size)
{
	char extra_char = 0, padd = ' ';
	int ind = BUFFER_SIZE - 2, length = 2,
	    padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map[] = "0123456789abcdef";
	void *addrs = va_arg(typ, void *);

	UNUSED(wid);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFFER_SIZE - 1] = '\0';
	UNUSED(pr);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map[num_addrs % 16];
		num_addrs /= 16;
		len++;
	}

	if ((flg & F_ZERO) && !(flg & F_MINUS))
		padd = '0';
	if (flg & F_PLUS)
		extra_char = '+', len++;
	else if (flg & F_SPACE)
		extra_char = ' ', len++;

	ind++;

	return (write_point(buffer, ind, length,
				wid, flg, padd, extra_char, padd_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @typ: arguments list
 * @buffer: inputed Buffer array
 * @flg: active flags
 * @wid: get width
 * @pr: get precision
 * @size: Size specifier
 * Return: Number of characters displayed
 */
int print_non_printable(va_list typ, char buffer[],
		int flg, int wid, int pr, int size)
{
	int a = 0, offset = 0;
	char *st = va_arg(typ, char *);

	UNUSED(flg);
	UNUSED(wid);
	UNUSED(pr);
	UNUSED(size);

	if (st == NULL)
		return (write(1, "(null)", 6));

	while (st[a] != '\0')
	{
		if (is_printable(str[a]))
			buffer[a + offset] = st[a];
		else
			offset += append_hexa_code(str[a], buffer, a + offset);

		a++;
	}

	buffer[a + offset] = '\0';

	return (write(1, buffer, a + offset));
}
/**
 * print_rev - Prints reverse string.
 * @typ: arguments list
 * @buffer:inputed  Buffer
 * @flg:  active flags
 * @wid: get width
 * @pr: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars displayed
 */

int print_rev(va_list typ, char buffer[],
		int flg, int wid, int pr, int size)
{
	char *st;
	int x, count = 0;

	UNUSED(buffer);
	UNUSED(flg);
	UNUSED(wid);
	UNUSED(size);

	st = va_arg(typ, char *);

	if (st == NULL)
	{
		UNUSED(pr);

		st = ")Null(";
	}
	for (x = 0; st[x]; x++)
		;

	for (x = x - 1; x >= 0; x--)
	{
		char z = st[x];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13str - Print a string in rot13.
 * @typ: arguments list
 * @buffer: inputed Buffer
 * @flg: active flags
 * @wid: get width
 * @pr: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars displayed
 */
int print_rot13str(va_list typ, char buffer[],
		int flg, int wid, int pr, int size)
{
	char x;
	char *str;
	unsigned int a, b;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(typ, char *);
	UNUSED(buffer);
	UNUSED(flg);
	UNUSED(wid);
	UNUSED(pr);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (a = 0; str[a]; a++)
	{
		for (b = 0; in[b]; b++)
		{
			if (in[b] == str[a])
			{
				x = out[b];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[b])
		{
			x = str[a];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);

