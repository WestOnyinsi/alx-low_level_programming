#include "main.h"

/**
 * clear_bit - settting value of bit to 0
 * @n: pointer
 * @index: index of chossen bit
 *
 * Return: 1 means success, -1 means fail
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
