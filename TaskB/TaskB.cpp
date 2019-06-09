#ifdef TASKB

#include "Library.h"

void task()
{
	typedef long T;
	const T MOD = 1e9 + 7;
	Matrix<T>::MOD = MOD;

	T N, L, M;
	read(N, L, M);

	vector<int> a(N + 1);
	vector<int> b(N + 1);
	vector<int> c(N + 1);
	read(N, a);
	read(N, b);
	read(N, c);

	Matrix<T> input(1, M);
	Matrix<T> city(M, M);

	REP(i, N) ++input(0, a[i] % M);
	REP(i, N)  ++city(0, b[i] % M);
	REP0(j, 1, M) REP0(i, M) city(j, i) = city(0, (M + i - j) % M);

	Matrix<T> cityL = city.pow(L - 2);
	Matrix<T> result = input * cityL;

	T ans = 0;
	REP(i, N) {
		T out = (b[i] + c[i]) % M;
		T required = (M - out) % M; 
		ans = (result(0, required) + ans) % MOD;
	}

	write(ans);
	return;
}

#endif