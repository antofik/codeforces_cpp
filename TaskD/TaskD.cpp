#ifdef TASKD

#include "Library.h"

void task()
{
	LL n;
	cin >> n;
	vector<string> words1(n);
	vector<string> words2(n);
	for (int i = 0; i < n; i++)
		cin >> words1[i];
	for (int i = 0; i < n; i++)
		cin >> words2[i];
	if (n == 1) {
		cout << "YES" << endl << words1[0] << endl << words2[0] << endl;
		return;
	}

	unordered_map<int, int> m;
	string w1, w2;
	string x1, x2;
	int d1, d2;
	for (int i = 0; i < n; i++) {
		// let us find diff for given word
		for (int j = 0; j < words1[i].length(); j++) {
			if (words1[i][j] != words2[i][j]) {
				m.emplace(i, j);
				int length = 0, k;
				for (k = words1[i].length() - 1; k >= j; k--) {
					if (words1[i][k] != words2[i][k]) {
						length = k - j + 1;
						break;
					}
				}

				string v1 = words1[i].substr(j, length);
				string v2 = words2[i].substr(j, length);
				if (w1.empty()) {
					// take as specific replacement as possible
					d1 = j; d2 = words1[i].length() - k - 1; // d1 - extra symbols to the left, d2 - to the right
					x1 = v1;
					x2 = v2;
					w1 = words1[i];
					w2 = words2[i];
				}
				else if (v1 != x1 || v2 != x2) {
					cout << "NO" << endl;
					return;
				}
				else {
					// replacement is ok, but let us 
					// widen it as much as possible
					int new_d1 = min(j, d1);
					for (int d = 1; d <= new_d1; d++) { // extend to left
						if (words1[i][j - d] != w1[d1 - d]) {
							new_d1 = d - 1;
							break;
						}
					}

					int new_d2 = min((int)words1[i].length() - k - 1, d2);
					for (int d = 1; d <= new_d2; d++) { // extend to right
						if (words1[i][j + x1.length() - 1 + d] != w1[d1 + x1.length() - 1 + d]) {
							new_d2 = d - 1;
							break;
						}
					}

					d1 = new_d1;
					d2 = new_d2;

					w1 = words1[i].substr(j - d1, x1.length() + d1 + d2);
					w2 = words2[i].substr(j - d1, x1.length() + d1 + d2);
				}
				break;
			}
		}
	}

	// we found replacement
	// let us check if it spoil any of the 
	// other words
	auto p = kmp(w1);
	for (int i = 0; i < n; i++) {
		auto it = m.find(i);
		const string& T = words1[i];
		auto index = find_kmp(words1[i], w1, p);

		if (it == m.end()) { // not in replacement list
			if (index != -1) {
				cout << "NO" << endl;
				return;
			}
		}
		else if (index + d1 < it->second) {
			// before targeted replacement there is a match
			cout << "NO" << endl;
			return;
		}
	}

	cout << "YES" << endl << w1 << endl << w2 << endl;
	return;
}

#endif