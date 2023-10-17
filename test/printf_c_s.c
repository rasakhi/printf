#include "main.h"
/**
 * handle_c_s_mod - Handles the 'c', 's', and '%' format specifiers
 * @buffer: The buffer to write to
 * @buff_count: The count of characters in the buffer
 * @args: The va_list of arguments
 * @format: The format specifier
 */
void handle_c_s_mod(char buffer[], int *buff_count, va_list args, char format)
{   char *str;
	if (*buff_count >= buffer_size)
		output_buffer(buffer, buff_count);
	if (format == 'c')
		buffer[(*buff_count)++] = (char)va_arg(args, int);
	else if (format == 's')
		for (str = va_arg(args, char *); *str; str++)
			buffer[(*buff_count)++] = *str;
	else if (format == '%')
		buffer[(*buff_count)++] = '%';
}
