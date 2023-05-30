#include "main.h"
/**
 * print_char - displays a character
 * @typ: arguments list
 * @buffer: inputed Buffer array
 * @flg:  active flags
 * @wid: Width
 * @pr: Precision specification
 * @size: Size specifier
 * Return: Number of chars displayed
 */
int print_char(va_list typ, char buffer[],
	int flg, int wid, int pr, int size)
{
	char c = va_arg(typ, int);

	return (write_char(c, buffer, flg, wid, pr, size));
}
/**
 * print_str - displays a string
 * @typ: arguments list
 * @buffer: inputed Buffer array
 * @flg: active flags
 * @wid:  width.
 * @pr: Precision specification
 * @size: Size specifier
 * Return: Number of chars displayed
 */
int print_str(va_list typ, char buffer[],
	int flg, int wid, int pr, int size)
{
	int len = 0, i;
	char *st = va_arg(typ, char *);

	UNUSED(buffer);
	UNUSED(flg);
	UNUSED(wid);
	UNUSED(pr);
	UNUSED(size);
	if (st == NULL)
	{
		st = "(null)";
		if (pr >= 6)
			st = "      ";
	}

	while (st[len] != '\0')
		len++;

	if (pr >= 0 && pr < len)
		len = pr;

	if (wid > len)
	{
		if (flg & F_MINUS)
		{
			write(1, &st[0], len);
			for (i = wid - len; i > 0; i--)
				write(1, " ", 1);
			return (wid);
		}
		else
		{
			for (i = wid - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &st[0], len);
			return (wid);
		}
	}

	return (write(1, st, len));
}

/**
 * print_per - Prints a percent sign
 * @typ: List of arguments
 * @buffer: inputed Buffer array
 * @flg: active flags
 * @wid: width.
 * @pr: Precision specification
 * @size: Size specifier
 * Return: Number of chars displayed
 */
int print_per(va_list typ, char buffer[],
	int flg, int wid, int pr, int size)
{
	UNUSED(typ);
	UNUSED(buffer);
	UNUSED(flg);
	UNUSED(wid);
	UNUSED(pr);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/**
 * print_int - Print int
 * @typ: List of arguments
 * @buffer:inputed Buffer array
 * @flg: active flags
 * @wid: width.
 * @pr: Precision specification
 * @size: Size specifier
 * Return: Number of chars displayed
 */
int print_int(va_list typ, char buffer[],
	int flg, int wid, int pr, int size)
{
	int i = BUFFER_SIZE - 2;
	int is_neg = 0;
	long int n = va_arg(typ, long int);
	unsigned long int num;

	n = conv_size_num(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_neg = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;
	return (write_num(is_neg, i, buffer, flg, wid, pr, size));

}

/**
 * print_binary - Prints an unsigned number
 * @typ: List of arguments
 * @buffer: inputed Buffer array
 * @flg: active flags
 * @wid: width.
 * @pr: Precision specification
 * @size: Size specifier
 * Return: Numbers of char displayed.
 */
int print_binary(va_list typ, char buffer[],
	int flg, int wid, int pr, int size)
{
	unsigned int x, y, a, sum;
	unsigned int i[32];
	int count;

	UNUSED(buffer);
	UNUSED(flg);
	UNUSED(wid);
	UNUSED(pr);
	UNUSED(size);

	x = va_arg(typ, unsigned int);
	y = 2147483648; /* (2 ^ 31) */
	i[0] = x / y;
	for (a = 1; a < 32; a++)
	{
		y /= 2;
		i[a] = (x / y) % 2;
	}
	for (a = 0, sum = 0, count = 0; a < 32; a++)
	{
		sum += i[a];
		if (sum || a == 31)
		{
			char z = '0' + i[a];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

