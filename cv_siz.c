#include "main.h"

/**
 * hand_size - the size to cast the argument to
 * @format: a format  string
 * @list_p: arguments to be printed.
 *
 * Return: size
 */
int hand_size(const char *format, int *list_p)
{
	int curr = *list_p + 1;
	int size = 0;

	if (format[curr] == 'l')
		size = S_LONG;
	else if (format[curr] == 'h')
		size = S_SHORT;

	if (size == 0)
		*list_p = curr - 1;
	else
		*list_p = curr;

	return (size);
}

