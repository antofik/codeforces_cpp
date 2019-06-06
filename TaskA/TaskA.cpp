#ifdef TASKA

#include "Library.h"

ULL dp[100000 + 2][2][202];

#define MEMSET(a,x) memset(&a,x,sizeof(a));
#define MEMZERO(a) MEMSET(a,0)

void read(int x) {
	scanf("%d", &x);
}

void task()
{
	MEMZERO(dp);

	const ULL MOD = 998244353;
	const int H = 200;

	int n;
	scanf("%d", &n);

	vector<int> a(n + 2);
	REP(i, n) scanf("%d", &a[i]);

	// dp[i][0][h] - how many combinations before a[i] when a[i+1]==h and a[i+2] < a[i+1]
	// dp[i][1] [h]- how many combinations before a[i] when a[i+1]==h and a[i+2] >= a[i+1]

	REP(h, H) {
		dp[0][1][h] = 1;
		dp[0][0][h] = 0;
	}
	dp[0][0][1] = 1;

	REP(i, n) {
		ULL s0[202] = { 0 };
		ULL s1[202] = { 0 };

		REP(h, H)  s1[h] = (s1[h - 1] + dp[i - 1][1][h]) % MOD;
		REPR(h, H) s0[h] = (s0[h + 1] + dp[i - 1][0][h]) % MOD;

		if (a[i] == -1) {
			REP(h, H) {
				dp[i][1][h] = (s1[h] + s0[h + 1]) % MOD;
				dp[i][0][h] = (dp[i - 1][1][h] + s0[h + 1]) % MOD;
			}
		}
		else {
			REP(h, H) {
				dp[i][1][h] = dp[i - 1][h >= a[i]][a[i]];
				dp[i][0][h] = h <= a[i] ? dp[i - 1][h >= a[i]][a[i]] : 0;
			}
		}
	}

	printf("%lld", dp[n][0][1]);
}

#endif