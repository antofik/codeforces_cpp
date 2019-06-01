#ifdef TASKB

#include "Library.h"

void task()
{
	LL n, m, l;
	cin >> n >> m >> l;

	vector<LL> a(n);

	LL result = 0;
	bool found = false;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		bool ok = a[i] > l;
		if (ok && !found) {
			found = true;
			result++;
		}
		else if (!ok && found) {
			found = false;
		}
	}

	for (int r = 0; r < m; r++) {

		int q;
		cin >> q;
		if (q == 0) {
			cout << result << endl;
		}
		else {
			int p, d;
			cin >> p >> d;
			p--;
			if (a[p] <= l && a[p] + d > l) {
				if (p > 0 && a[p - 1] > l && p < n - 1 && a[p + 1] > l) {
					result--;
				}
				else if ((p == 0 || a[p - 1] <= l) && (p == n - 1 || a[p + 1] <= l)) {
					result++;
				}
			}
			a[p] += d;
		}
	}
}

#endif