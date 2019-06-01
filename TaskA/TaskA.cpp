#ifdef TASKA

#include "Library.h"

void task()
{
	LL n, s;
	cin >> n >> s;
	s--;

	vector<bool> a(n);
	vector<bool> b(n);

	for (int i = 0; i < n; i++) {
		int ch;
		cin >> ch;
		a[i] = ch == 1;
	}
	for (int i = 0; i < n; i++) {
		int ch;
		cin >> ch;
		b[i] = ch == 1;
	}

	bool result = false;
	if (a[0]) {
		if (a[s]) {
			result = true;
		}
		else if (b[s]) {
			for (int i = s + 1; i < n; i++) {
				if (a[i] && b[i]) {
					result = true;
					break;
				}
			}
		}
	}

	cout << (result ? "YES" : "NO");
}

#endif