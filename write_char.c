#include <unistd.h>
/**
 * write_char - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, 0 is returned, and errno is set appropriately.
 */
int write_char(char c)
{
	return (write(1, &c, 1));
}

