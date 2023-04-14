#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text
 * @filename: subject read
 * @letters: letters read
 * Return: actual number of bytes read and printe & 0 if fails or filename NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffy;
	ssize_t fdfd;
	ssize_t wxyz;
	ssize_t t;

	fdfd = open(filename, O_RDONLY);
	if (fdfd == -1)
		return (0);
	buffy = malloc(sizeof(char) * letters);
	t = read(fdfd, buffy, letters);
	wxyz = write(STDOUT_FILENO, buffy, t);

	free(buffy);
	close(fdfd);
	return (wxyz);
}
