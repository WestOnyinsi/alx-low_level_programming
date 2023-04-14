#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * @file: blehblehbleh
 */
char *create_buffer(char *file)
{
	char *bufferizer;

	bufferizer = malloc(sizeof(char) * 1024);

	if (bufferizer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (bufferizer);
}

/**
 * @fd: blehhuuicuih iojdsichihci iojeiojcjeiojcioej iojheiojfiojehoifjeiofj iruouyturopwu
 */
void close_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * @argc: bleh
 * @argv: blehblehjdughduihdue duihduihuid
 *
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *bufferizer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	bufferizer = create_bufferizer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, bufferizer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(bufferizer);
			exit(98);
		}

		w = write(to, bufferizer, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(bufferizer);
			exit(99);
		}

		r = read(from, bufferizer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(bufferizer);
	close_file(from);
	close_file(to);

	return (0);
}
