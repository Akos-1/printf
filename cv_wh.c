#include "main.h"

/**
 * write_char - Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flg:  Calculates active flags.
 * @wid: get width.
 * @pr: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_char(char c, char buffer[],
		int flg, int wid, int pr, int size)
{
	int a = 0;
	char padd = ' ';

	UNUSED(pr);
	UNUSED(size);

	if (flg & F_ZERO)
		padd = '0';

	buffer[a++] = c;
	buffer[a] = '\0';

	if (wid > 1)
	{
		buffer[BUFFER_SIZE - 1] = '\0';
		for (a = 0; a < wid - 1; a++)
			buffer[BUFFER_SIZE - a - 2] = padd;

		if (flg & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFFER_SIZE - a - 1], wid - 1));
		else
			return (write(1, &buffer[BUFFER_SIZE - a - 1], wid - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * write_num - Prints a string
 * @is_neg: List of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flg:  Calculates active flags
 * @wid: get width.
 * @pr: precision specifier
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int write_num(int is_neg, int ind, char buffer[],
		int flg, int wid, int pr, int size)
{
	int len = BUFFER_SIZE - ind - 1;
	char padd = ' ', extra_char = 0;

	UNUSED(size);

	if ((flg & F_ZERO) && !(flg & F_MINUS))
		padd = '0';
	if (is_neg)
		extra_char = '-';
	else if (flg & F_PLUS)
		extra_char = '+';
	else if (flg & F_SPACE)
		extra_char = ' ';

	return (write_numb(ind, buffer, flg, wid, pr,
				len, padd, extra_char));
}

/**
 * write_numb - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flg: Flags
 * @wid: width
 * @pre: Precision specifier
 * @len: Number length
 * @padd: Pading char
 * @extra_char: Extra char
 *
 * Return: Number of printed chars.
 */
int write_numb(int ind, char buffer[],
		int flg, int wid, int pre,
		int len, char padd, char extra_char)
{
	int x, padd_start = 1;

	if (pre == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0' && wid == 0)
		return (0);
	if (pre == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (pre > 0 && pre < len)
		padd = ' ';
	while (pre > len)
		buffer[--ind] = '0', len++;
	if (extra_char != 0)
		len++;
	if (wid > len)
	{
		for (x = 1; x < wid - len + 1; x++)
			buffer[x] = padd;
		buffer[x] = '\0';
		if (flg & F_MINUS && padd == ' ')
		{
			if (extra_char)
				buffer[--ind] = extra_char;
			return (write(1, &buffer[ind], len) + write(1, &buffer[1], x - 1));
		}
		else if (!(flg & F_MINUS) && padd == ' ')/* extra char to left of buff */
		{
			if (extra_char)
				buffer[--ind] = extra_char;
			return (write(1, &buffer[1], x - 1) + write(1, &buffer[ind], len));
		}
		else if (!(flg & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_char)
				buffer[--padd_start] = extra_char;
			return (write(1, &buffer[padd_start], x - padd_start) +
					write(1, &buffer[ind], len - (1 - padd_start)));
		}
	}
	if (extra_char)
		buffer[--ind] = extra_char;
	return (write(1, &buffer[ind], len));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @is_neg: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flg: Flags specifiers
 * @wid: Width specifier
 * @pre: Precision specifier
 * @size: Size specifier
 * Return: Number of written chars.
 */
int write_unsgnd(int is_neg, int ind,
		char buffer[],
		int flg, int wid, int pre, int size)
{
	int le = BUFFER_SIZE - ind - 1, a = 0;
	char padd = ' ';

	UNUSED(is_neg);
	UNUSED(size);

	if (pre == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (pre > 0 && pre < le)
		padd = ' ';

	while (pre > le)
	{
		buffer[--ind] = '0';
		le++;
	}

	if ((flg & F_ZERO) && !(flg & F_MINUS))
		padd = '0';

	if (wid > le)
	{
		for (a = 0; a < wid - le; a++)
			buffer[a] = padd;

		buffer[a] = '\0';

		if (flg & F_MINUS)
		{
			return (write(1, &buffer[ind], le) + write(1, &buffer[0], a));
		}
		else /* Asign extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &buffer[0], a) + write(1, &buffer[ind], le));
		}
	}

	return (write(1, &buffer[ind], le));
}

/**
 * write_point - Write a memory address
 * @buffer: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @len: Length of number
 * @wid: Wwidth specifier
 * @flg: Flags specifier
 * @padd: Char representing the padding
 * @extra_char: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int write_point(char buffer[], int ind, int len,
		int wid, int flg, char padd, char extra_char, int padd_start)
{
	int a;

	if (wid > len)
	{
		for (a = 3; a < wid - len + 3; a++)
			buffer[a] = padd;
		buffer[a] = '\0';
		if (flg & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_char)
				buffer[--ind] = extra_char;
			return (write(1, &buffer[ind], len) + write(1, &buffer[3], a - 3));
		}
		else if (!(flg & F_MINUS) && padd == ' ')/* extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_char)
				buffer[--ind] = extra_char;
			return (write(1, &buffer[3], a - 3) + write(1, &buffer[ind], len));
		}
		else if (!(flg & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_char)
				buffer[--padd_start] = extra_char;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], a - padd_start) +
					write(1, &buffer[ind], len - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_char)
		buffer[--ind] = extra_char;
	return (write(1, &buffer[ind], BUFFER_SIZE - ind - 1));
}

