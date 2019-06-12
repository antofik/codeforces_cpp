#ifdef TASKD

#include "Library.h"

void task()
{
	// h(h+1)/2 = 4e5 => h<900
	// hh + h - 2rg = 0 => hh + 2h*1/2 + 1/4 = 1/4 + 2rg => h=sqrt(1/4+2rg) - 1/2

	const int MOD = 1000000007;

	int R, G;
	read(R, G);

	const int H = (int)floor(sqrt(0.25 + 2*(R + G)) - 0.5); // max(H)=900
	int reminder = R + G - H * (H + 1) / 2;
	if (R > G) swap(R, G); // R <= G
	const int totalCount = H * (H + 1) / 2;
	int minR = max(0, totalCount - G);
	int maxR = H * (H + 3) / 4;

	vector<int> cur(200001);
	vector<int> prev(200001);

	REP(h, H) {
		fill(cur.begin(), cur.end(), 0);
		if (h==1) cur[0] = 1;
		cur[h] = 1;
		REP(r, h + 1, min(maxR, h * (h + 1) / 2))
			cur[r] = prev[r - h];
		REP(r, 0, maxR)
			cur[r] = (cur[r] + prev[r]) % MOD;
		swap(cur, prev);
	}

	int ans = 0;
	REP(r, minR, R) ans = (ans + prev[r]) % MOD;
	write(ans);
}

#endif