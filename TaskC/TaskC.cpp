#ifdef TASKC

#include "Library.h"
#include <cmath>

typedef long long LL;
using namespace std;

LL max(LL a, LL b) {
	return a > b ? a : b;
}

LL min(LL a, LL b) {
	return a > b ? b : a;
}

LL gcd(LL a, LL b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

void task()
{
	LL l1, r1, t1, l2, r2, t2;
	cin >> l1 >> r1 >> t1;
	cin >> l2 >> r2 >> t2;
	LL g = gcd(t1, t2);

	// success days offset
	LL dif = (l1 - l2 + g) % g;

	// success days length
	LL s1 = r1 - l1 + 1;
	LL s2 = r2 - l2 + 1;

	// normalize offsets
	l1 %= g;
	l2 %= g;

	// overlap of two lines [x1,y1) and [x2,y2) is max(0, min(y1,y2) - max(x1,x2))
	LL overlap1 = max(0, min(l1 + s1, l2 + s2) - max(l1, l2));

	// offset leftmost line on g to the right
	(l1 < l2 ? l1 : l2) += g;
	LL overlap2 = max(0, min(l1 + s1, l2 + s2) - max(l1, l2));
	cout << max(overlap1, overlap2);
}

#endif