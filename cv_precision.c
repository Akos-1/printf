#include "main.h"

/**
 * hand_pr - gets the precision for printing
 * @format: format string
 * @list_p: List of arguments being printed
 * @argu: list of args
 *
 * Return: Precision.
 */
int hand_pr(const char *format, int *list_p, va_list argu)
{
	int current = *list_p + 1;
	int pr = -1;

	if (format[current] != '.')
		return (pr);

	pr = 0;

	for (current += 1; format[current] != '\0'; current++)
	{
		if (is_dig(format[current]))
		{
			pr *= 10;
			pr += format[current] - '0';
		}
		else if (format[current] == '*')
		{
			current++;
			pr = va_arg(argu, int);
			break;
		}
		else
			break;
	}

	*list_p = current - 1;

	return (pr);
}

