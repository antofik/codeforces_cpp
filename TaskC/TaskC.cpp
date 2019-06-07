#ifdef TASKC

#include "Library.h"

struct S {
	ULL a, b, c;
	int i;
};

ULL dp[52][52][102];

void task()
{
	memset(&dp, 0, sizeof(dp));

	S s;
	int n, m, k;
	read(n, m, k);
	vector<S> v(m + 1);
	REP(i, m) {
		read(v[i].a, v[i].b, v[i].c);
		v[i].i = i;
	}
	std::sort(v.begin(), v.end(), [](auto& a, auto& b) { return a.c < b.c; });

	if (n == 1) {
		write("YES");
		std::sort(v.begin(), v.end(), [](auto& a, auto& b) { return a.b > b.b; });
		printf("%lld %lld", ULL(v[0].i), v[0].b);
		return;
	}

	REP(i, m) REP(j, 0, v[i].b - v[i].a) dp[i][1][j] = v[i].a + j;

	// dp[i][z][j] - max cost of z out of 1..i subjects, including i-th with cost j
	vector<int> best(3);
	ULL bestCost = 0;
	REP(i, m) {
		REP(z, 2, min(n,i)) {			
			REP(j, 0, v[i].b - v[i].a) {
				ULL current = v[i].a + j;
				if (current >= k) {
					ULL previous = current - k;
					REP(h, z - 1, i - 1)
						if (v[h].a <= previous && previous <= v[h].b && dp[h][z - 1][previous - v[h].a] && v[h].c < v[i].c) {
							dp[i][z][j] = max(dp[i][z][j], dp[h][z - 1][previous - v[h].a] + current);
						}
				}
				REP(h, z-1, i - 1) {
					if (current % k != 0) continue;
					ULL previous = current / k;
					if (v[h].a <= previous && previous <= v[h].b && dp[h][z - 1][previous - v[h].a] && v[h].c < v[i].c) {
						dp[i][z][j] = max(dp[i][z][j], dp[h][z - 1][previous - v[h].a] + current);
					}
				}
				if (z == n && dp[i][z][j] > bestCost) {
					bestCost = dp[i][z][j];
					best = { i,z,j };
				}
			}
		}
	}

	if (bestCost == 0) {
		write("NO");
		return;
	}

	write("YES");	
	vector<pair<ULL, ULL>> solution(n+1);
	RER(i, n) {
		ULL cost = v[best[0]].a + best[2];
		solution[i] = { v[best[0]].i, cost };
		bestCost -= cost;
		if (i > 1) {
			RER(h, best[0] - 1) {
				bool found = false;
				REP(j, 0, v[h].b - v[h].a) {
					ULL c = v[h].a + j;
					if ((c + k == cost || c * k == cost) && dp[h][i - 1][j] == bestCost && v[h].c < v[best[0]].c) {
						cost = c;
						best = { h, 0, j };
						found = true;
						break;
					}
				}
				if (found) break;
			}
		}
	}

	REP(i, n) {
		write(solution[i].first, solution[i].second);
	}
}

#endif