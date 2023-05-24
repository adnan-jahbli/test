#include "main.h"

/**
 * split_buffer - a function that splits a given buffer
 * of multiple lines to seperated lines.
 * @buffer: the given buffer
 * @end_of_line: where each line of the buffer ends
 * @size: size of each line
 *
 * Return: each line of the file
 */
char *split_buffer(char *buffer, int *end_of_line, ssize_t size)
{
	char *line;
	int i, j, y;

	(void) y;
	if (*end_of_line >= size)
		return (NULL);

	for (i = *end_of_line; i < size; i++)
	{
		if (buffer[i] == '\n')
			break;
	}

	line = malloc(i - *end_of_line + 1);
	if (!line)
	{
		y = write(STDERR_FILENO, "Error: malloc failed\n", 22);
		exit(98);
	}
	for (j = 0; j < i - *end_of_line; j++)
		line[j] = buffer[*end_of_line + j];
	line[j] = '\n';

	*end_of_line = i + 1;

	return (line);
}
