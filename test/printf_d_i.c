#include "main.h"

/**
 * handle_d - handles the %d directive
 * @buffer: array of characters
 * @buff_count: number of bytes
 * @args: variadic arguement
 * Return: Nothing
 */
void handle_d(char buffer[], int *buff_count, va_list args)
{
	int num = va_arg(args, int), i = 0, j;
	char str_num[12], *str;

	if (num == 0)
		str_num[i++] = '0';
	else
	{
		if (num < 0)
		{
			buffer[(*buff_count)++] = '-';
			num = -num;
		}
		for (; num > 0; num /= 10)
			str_num[i++] = '0' + num % 10;
	}
	for (j = 0; j < i / 2; j++)
	{
		char temp = str_num[j];

		str_num[j] = str_num[i - j - 1];
		str_num[i - j - 1] = temp;
	}
	str_num[i] = '\0';
	for (str = str_num; *str; str++)
	{
		if (*buff_count >= buffer_size)
			output_buffer(buffer, buff_count);
		buffer[(*buff_count)++] = *str;
	}
}
