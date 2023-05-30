#include "main.h"
/**
 * hand_wid - the width for display is calculated.
 * @format: Formatted string
 * @list_p: arguments list
 * @argu: list of arguments.
 * Return: wid.
 */
int hand_wid(const char *format, int *list_p, va_list argu)
{
	int present;
	int wid = 0;

	for (present = *list_p + 1; format[present] != '\0'; present++)
	{
		if (is_dig(format[present]))
		{
			wid *= 10;
			wid += format[present] - '0';
		}
		else if (format[present] == '*')
		{
			present++;
			wid = va_arg(argu, int);
			break;
		}
		else
			break;
	}

	*list_p = present - 1;

	return (wid);
}
