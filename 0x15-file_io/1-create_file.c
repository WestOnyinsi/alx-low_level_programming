#include "main.h"

/**
 * @filename: pointer to namefile
 * @text_content: pointerstring to file.
 */
int create_file(const char *filename, char *text_content)
{
	int fdfd, wxyz, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	fdfd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wxyz = write(fdfd, text_content, length);

	if (fdfd == -1 || wxyz == -1)
		return (-1);

	close(fdfd);

	return (1);
}
