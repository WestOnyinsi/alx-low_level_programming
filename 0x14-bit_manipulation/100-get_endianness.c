#include "main.h"

/**
 * function that checks machine endian size 
 * Return 0-big || 1-little
 */
int get_endianness(void)
{
	unsigned int mnatuchosha = 1;
	char *c = (char *) &mnatuchosha;

	return (*c);
}
