#include "main.h"

/** 
 * print bin == of dec num
 */
void print_binary(unsigned long int n)
{
	int xx, intcount = 0;
	unsigned long int current;

	for (xx = 63; xx >= 0; xx--)
	{
		current = n >> xx;

		if (current & 1)
		{
			_putchar('1');
			intcount++;
		}
		else if (intcount)
			_putchar('0');
	}
	if (!intcount)
		_putchar('0');
}
