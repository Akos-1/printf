#include "main.h"
/**
* print_unsigned - displays an unsigned number
 * @typ: arguments list
 * @buffer: inputed Buffer array
 * @flg: active flags
 * @wid: width
 * @pr: Precision specification
 * @size: Size specifier
 * Return: Number of chars displayed.
 */
int print_unsgnd(va_list typ, char buffer[],
	int flg, int wid, int pr, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(typ, unsigned long int);

	num = conv_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (wr_unsigned(0, i, buffer, flg, wid, pr, size));
}

/**
 * print_oct - displays an unsigned number in octal notation
 * @typ: arguments list
 * @buffer: inputed Buffer array
 * @flg: active flags
 * @wid: width
 * @pr: Precision specification
 * @size: Size specifier
 * Return: Number of chars displayed
 */
int print_oct(va_list typ, char buffer[],
	int flg, int wid, int pr, int size)
{

	int a = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(typ, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(wid);

	num = conv_size_unsgnd(num, size);

	if (num == 0)
		buffer[a--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = (num % 8) + '0';
		num /= 8;
	}

	if (flg & F_HASH && init_num != 0)
		buffer[a--] = '0';

	a++;

	return (wr_unsigned (0, a, buffer, flg, wid, pr, size));
}

/**
 * print_hexadec - Prints an unsigned number in hexadecimal notation
 * @typ: List of arguments
 * @buffer: Buffer array to handle print
 * @flg:  Calculates active flags
 * @wid: get width
 * @pr: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadec(va_list typ, char buffer[],
	int flg, int wid, int pr, int size)
{
	return (print_hexa(typ, "0123456789abcdef", buffer,
		flg, 'x', wid, pr, size));
}

/**
 * print_hexa_upp - Prints an unsigned number in upper hexadecimal notation
 * @typ: List of arguments
 * @buffer: Buffer array to handle print
 * @flg:  Calculates active flags
 * @wid: get width
 * @pr: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_upp(va_list typ, char buffer[],
	int flg, int wid, int pr, int size)
{
	return (print_hexa(typ, "0123456789ABCDEF", buffer,
		flg, 'X', wid, pr, size));
}

/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @typ: arguments list
 * @map: Array of values to be mapped to
 * @buffer: inputed Buffer array
 * @flg: active flags
 * @flg_ch: Calculates active flags
 * @wid: width
 * @pr: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars displayed
 */
int print_hexa(va_list typ, char map[], char buffer[],
	int flg, char flg_ch, int wid, int pr, int size)
{
	int c = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(typ, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(wid);

	num = conv_size_unsgnd(num, size);

	if (num == 0)
		buffer[c--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[c--] = map[num % 16];
		num /= 16;
	}

	if (flg & F_HASH && init_num != 0)
	{
		buffer[c--] = flg_ch;
		buffer[c--] = '0';
	}

	c++;

	return (wr_unsigned (0, c, buffer, flg, wid, pr, size));
}

