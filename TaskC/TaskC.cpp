#ifdef TASKC

#include "Library.h"

const ULL MAX = 1e15;
ULL dp[5010][5010];
ULL best[5010][5010];

void task()
{
	memset(&dp, 0xEE, sizeof(dp));
	memset(&best, 0xEE, sizeof(best));

	int n;
	scanf("%d", &n);
	vector<int> a(n+1);
	REP(i,n) scanf("%d", &a[i]);

	REP(i, 0, n) best[i][0] = dp[i][0] = 0;
	dp[1][1] = 0;
	dp[2][1] = a[1] == a[2] ? 1 : 0;
	best[2][1] = max(0, a[2] - a[1] + 1);
	
	REP(i, 3, n) {	
		REP(j, 1, (i + 1) / 2) {
			dp[i][j] = min(
				dp[i-2][j-1] + max(0, a[i-1] - min(a[i], a[i-2]) + 1),
				best[i-2][j-1] + max(0, a[i-1] - a[i] + 1)
			);
			
			best[i][j] = min(
				best[i-1][j],
				dp[i-1][j] + max(0, a[i] - a[i-1] + 1)
			);
		}
	}

	REP(i, (n + 1) / 2) {
		printf("%lld ", min(dp[n][i], best[n][i]));
	}
}

#endif