#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string with zero or more directives
 *
 * Return: Number of charcters printed or -1 if NULL
 */
int _printf(const char *format, ...)
{
	char buffer[buffer_size];
	int buff_count = 0;
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c': case 's': case '%':
				handle_c_s_mod(buffer, &buff_count, args, *format);
				break;
			case 'd': case 'i':
				handle_d(buffer, &buff_count, args);
				break;
			case '\0':
				break;
			default:
				_printf("Unknown specifier %%%c\n", *format);
				return (-1);
			}

		}
		else
		{
			if (buff_count >= buffer_size)
				output_buffer(buffer, &buff_count);
			buffer[buff_count++] = *format;
		}
		format++;
	}

	output_buffer(buffer, &buff_count);
	va_end(args);
	return (buff_count);
}
