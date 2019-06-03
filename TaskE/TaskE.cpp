#ifdef TASKE

#include "Library.h"

void task()
{
	int n, m;
	scanf("%d%d", &n, &m);

	vector<ULL> dp(m+1);
	
	REP(i, n) {
		int count;
		scanf("%d", &count);
		vector<ULL> s(count+1);
		REP(j, 1, count+1) {          // 1 1 1 1 1
			scanf("%lld", &s[j]);     // 1 2 3 4 5
			s[j] += s[j - 1];
		}

		int max_objects = min(count, m);
		vector<ULL> t(max_objects + 1);
		REP(j, max_objects + 1) {
			REP(k, max_objects - j + 1) {
				t[j + k] = max(t[j + k], s[j] + s[count] - s[count - k]);
			}
		}

		vector<ULL> d(m + 1);

		REP(j, max_objects + 1) {
			REP(k, m-j + 1) {
				d[j + k] = max(d[j + k], dp[k] + t[j]);
			}
		}
		
		dp.swap(d);
	}
	
	printf("%lld", dp[m]);
}

#endif