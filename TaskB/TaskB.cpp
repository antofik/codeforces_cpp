#ifdef TASKB

#include "Library.h"

void task()
{
	ULL n, m;
	read(n, m);

	ULL x = n - m + 1;
	ULL max = x * (x - 1) / 2;

	x = n / m;
	ULL k = n % m; // k pairs of x+1 and (m-k) pairs of x
	ULL min = k * x * (x + 1) / 2 + (m - k) * x * (x - 1) / 2;

	write(min, max);
}

#endif