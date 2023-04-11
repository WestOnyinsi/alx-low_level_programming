#include "main.h"

/**
 * function that counts bits to change
 * Returns no. of bits changed
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int xy, xycount = 0;
	unsigned long int currentxy;
	unsigned long int intexc = n ^ m;

	for (xy = 63; xy >= 0; xy--)
	{
		currentxy = intexc >> xy;
		if (currentxy & 1)
			xycount++;
	}

	return (xycount);
}
