#include "main.h"
/**
 * hand_flg - active flags is calculated
 * @format: string formatted
 * @x: take a parameter.
 * Return: Flags:
 */
int hand_flg(const char *format, int *x)
{
	int b, current;
	int flg = 0;
	const char FLG_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLG_AR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current = *x + 1; format[current] != '\0'; current++)
	{
		for (b = 0; FLG_CHAR[b] != '\0'; b++)
			if (format[current] == FLG_CHAR[b])
			{
				flg |= FLG_AR[b];
				break;
			}

		if (FLG_CHAR[b] == 0)
			break;
	}

	*x = current - 1;

	return (flg);
}
