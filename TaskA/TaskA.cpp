#ifdef TASKA

#include "Library.h"

ULL dp[100000 + 2][202][2];

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

	// dp[i][h][0] - how many combinations before a[i] when a[i+1]==h and a[i+2] < a[i+1]
	// dp[i][h][1] - how many combinations before a[i] when a[i+1]==h and a[i+2] >= a[i+1]

	REP(h, H) {
		dp[0][h][1] = 1;
		dp[0][h][0] = 0;
	}
	dp[0][1][0] = 1;

	REP(i, n) {
		//printf("--- i=%d a[i]=%d ----\n", i, a[i]);
		REP(h, H) {
			if (a[i] == -1) {
				REP(k, H) dp[i][h][1] += dp[i - 1][k][h >= k];
				REP(k, h, H) dp[i][h][0] += dp[i - 1][k][h >= k];
			}
			else {
				REP(h, H) {
					dp[i][h][1] = dp[i - 1][a[i]][h >= a[i]];
					dp[i][h][0] = h <= a[i] ? dp[i - 1][a[i]][h >= a[i]] : 0;
				}
			}
			//if (h < 5) printf("h=%d\t%lld\t%lld\n", h, dp[i][h][0], dp[i][h][1]);
		}
	}

	printf("%lld", dp[n][1][0]);
}

#endif