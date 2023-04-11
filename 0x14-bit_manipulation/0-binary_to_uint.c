#include "main.h"

/**
 * @b is the string that has bin num
  * Return converted num
 */
unsigned int binary_to_uint(const char *b)
{
	int x;
	unsigned int unint = 0;

	if (!b)
		return (0);

	for (x = 0; b[x]; x++)
	{
		if (b[x] < '0' || b[x] > '1')
			return (0);
		unint = 2 * unint + (b[x] - '0');
	}

	return (unint);
}
