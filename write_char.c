#include <unistd.h>
/**
 * write_char - writes the character c to stdout
 * @c: The character to print
 * @chars_displayed: characters displayed
 * Return: On success 1.
 * On error, 0 is returned, and errno is set appropriately.
 */
int write_char(char c, int *chars_displayed)
{
	int result = write(1, &c, 1);

	if (result > 0)
	{
		(*chars_displayed)++;
	}
	return (result);
}

