#ifdef TASKD

#include "Library.h"
#include <algorithm>
#include <cctype>

ULL dp[4][100010] = { 0 };
char s[100010] = { 0 };

void task()
{
#ifdef _DEBUG
	memset(&dp, 0, sizeof(dp));
	memset(&s, 0, sizeof(s));
#endif

	int n;
	scanf("%lld", &n);

	vector<ULL> a(n);

	scanf("%s", s);
	REP(i, n) 
		scanf("%lld", &a[i]);

	REP(i,n) REP(c, 4) {
		char ch = s[i];
		switch (ch) {
		case 'h':
		{
			dp[0][i + 1] = dp[0][i] + a[i];
			dp[1][i + 1] = dp[1][i];
			dp[2][i + 1] = dp[2][i];
			dp[3][i + 1] = dp[3][i];
			break;
		}
		case 'a':
		{
			dp[0][i + 1] = dp[0][i];
			dp[1][i + 1] = min(dp[0][i], dp[1][i] + a[i]);
			dp[2][i + 1] = dp[2][i];
			dp[3][i + 1] = dp[3][i];
			break;
		}
		case 'r':
		{
			dp[0][i + 1] = dp[0][i];
			dp[1][i + 1] = dp[1][i];
			dp[2][i + 1] = min(dp[1][i], dp[2][i] + a[i]);
			dp[3][i + 1] = dp[3][i];
			break;
		}
		case 'd':
		{
			dp[0][i + 1] = dp[0][i];
			dp[1][i + 1] = dp[1][i];
			dp[2][i + 1] = dp[2][i];
			dp[3][i + 1] = min(dp[2][i], dp[3][i] + a[i]);
			break;
		}
		default:
		{
			dp[0][i + 1] = dp[0][i];
			dp[1][i + 1] = dp[1][i];
			dp[2][i + 1] = dp[2][i];
			dp[3][i + 1] = dp[3][i];
			break;
		}
		}
	}

	ULL answer = min(dp[0][n], min(dp[1][n], min(dp[2][n], dp[3][n])));
	printf("%lld", answer);
}

#endif