#include "main.h"

/**
 * function to return value of a bit in a decimal num
 *
 * Returns the bit value
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bval;

	if (index > 63)
		return (-1);

	bval = (n >> index) & 1;

	return (bval);
}
