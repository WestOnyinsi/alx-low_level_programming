#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fdcdtdftff);

/**
 * @file:hifuhuih 6bh6jb6b6b bb4bb664765b4 yvu
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * @fdcdtdftff: bdvhsyg7 78y78  7t7 t 7g u7  r   u d
 */
void close_file(int fdcdtdftff)
{
	int c;

	c = close(fdcdtdftff);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fdcdtdftff %d\n", fdcdtdftff);
		exit(100);
	}
}

/**
 * @argc: cgf78ct7teg7t8t3v v78rg87 8tr7e v6e 7rv6cte76co7t37o7t3o7t t fgf7 6dtocgd7g
 * @argv: dgcfuyn7tx67t667 6rb  br6r68     e5 e e5 b e e 5 8edyf fvv h v v 
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(to, buffer, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		r = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
