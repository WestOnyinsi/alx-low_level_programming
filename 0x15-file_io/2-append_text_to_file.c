#include "main.h"

/**
 * @filename: bleh
 * @text_content: blehbleh
  */
int append_text_to_file(const char *filename, char *text_content)
{
	int ophelia, WIN, lenny = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (lenny = 0; text_content[lenny];)
			lenny++;
	}

	ophelia = open(filename, O_WRONLY | O_APPEND);
	WIN = write(ophelia, text_content, lenny);

	if (ophelia == -1 || WIN == -1)
		return (-1);

	close(ophelia);

	return (1);
}
