#ifdef TASKB

#include "Library.h"

const int MAX = 1004;
ULL a[MAX][MAX] = { 0 };
ULL t[MAX][MAX] = { 0 };
ULL d[MAX][MAX] = { 0 };
ULL l[MAX][MAX] = { 0 };
ULL r[MAX][MAX] = { 0 };
ULL dp[MAX][MAX] = { 0 };


void task()
{
#ifdef _DEBUG
	memset(&a, 0, sizeof(dp));
	memset(&t, 0, sizeof(dp));
	memset(&d, 0, sizeof(dp));
	memset(&l, 0, sizeof(dp));
	memset(&r, 0, sizeof(dp));
	memset(&dp, 0, sizeof(dp));
#endif

	int n, m;
	~scanf("%d%d", &n, &m);
	REP(i, n) REP(j, m) {
		~scanf("%lld", &a[i+1][j+1]);
	}

	REP(i, 1, n + 1) REP(j, 1, m + 1) t[i][j] = a[i][j] + max(t[i - 1][j], t[i][j - 1]);
	REPR(i, n, 1) REP(j, 1, m + 1) l[i][j] = a[i][j] + max(l[i + 1][j], l[i][j - 1]);
	REP(i, 1, n+1) REPR(j, m, 1) r[i][j] = a[i][j] + max(r[i - 1][j], r[i][j + 1]);
	REPR(i, n, 1) REPR(j, m, 1) d[i][j] = a[i][j] + max(d[i + 1][j], d[i][j + 1]);
	ULL ans = 0;
	REP(i, 2, n) REP(j, 2,  m) {
		ULL in = max(
			t[i][j - 1] + d[i][j + 1] + r[i - 1][j] + l[i + 1][j],
			t[i - 1][j] + d[i + 1][j] + r[i][j + 1] + l[i][j - 1]
		);
		ans = max(ans, in);
	}
	printf("%lld\n", ans);
}

#endif