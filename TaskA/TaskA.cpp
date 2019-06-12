#ifdef TASKA

#include "Library.h"

void task()
{
	int c1, c2, c3, c4, c5;
	read(c1, c2, c3, c4, c5);

	int sum = c1 + c2 + c3 + c4 + c5;
	if (sum % 5 == 0 && sum > 0)
		write(sum / 5);
	else
		write(-1);
}

#endif