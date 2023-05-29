#include "main.h"

/**
 * is_print - checks if a character can be printed
 * @a: Char to be checked.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_print(char a)
{
	if (a >= 32 && a < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append asccii to buffer
 * @buffer: Array of chars.
 * @x: Index at which to start appending.
 * @ascii: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii, char buffer[], int x)
{
	char map[] = "0123456789ABCDEF";

	if (ascii < 0)
		ascii *= -1;

	buffer[x++] = '\\';
	buffer[x++] = 'x';

	buffer[x++] = map[ascii / 16];
	buffer[x] = map[ascii % 16];

	return (3);
}

/**
 * is_dig -checks if a char is a digit
 * @a: Character to be checked
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_dig(char a)
{
	if (a >= '0' && a <= '9')
		return (1);

	return (0);
}

/**
 * conv_size_num - Casts a number to the specified size
 * @num: Number
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int conv_size_num(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * conv_size_unsgnd - Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int conv_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
