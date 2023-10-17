#include "main.h"

/**
 * output_buffer - writes characters to standard output
 * @buffer: array of characters
 * @buff_count: number of bytes
 * Return: Nothing
 */
void output_buffer(char buffer[], int *buff_count)
{
	write(1, buffer, *buff_count);
}
