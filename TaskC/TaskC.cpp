#ifdef TASKC

#include "Library.h"

typedef int T;
constexpr T MAX = 101;
constexpr T MAX2 = MAX * MAX;

int sums[MAX+1][MAX+1][12] = { 0 };

void task()
{
	T n, q, c;
	scanf("%d%d%d", &n, &q, &c);
	++c; 

	REP(i,n) {
		int x, y, s;
		scanf("%d%d%d", &x, &y, &s);
		sums[x][y][s]++;
	}

	REP(k, c) REPS(i, 1, MAX) REPS(j, 1, MAX) {
		sums[i][j][k] += sums[i-1][j][k] + sums[i][j-1][k] - sums[i-1][j-1][k];
	}

	REP(i, q) {
		T t, x1, y1, x2, y2;
		scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
		x1 -= 1; y1 -= 1;
		T result = 0;
		REP(j, c) {
			int count = sums[x1][y1][j] + sums[x2][y2][j] - sums[x1][y2][j] - sums[x2][y1][j];
			result += count * ((t+j) % c);
		}
		printf("%d\n", result);
	}
}

#endif