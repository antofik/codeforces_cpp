#pragma once

#include <iostream>
#include <streambuf>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <locale>
#include <functional>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

// ------------------- types ------------------------------

typedef long L;
typedef unsigned long UL;
typedef unsigned long long ULL;
typedef unsigned long long ULL;

// ------------------- macros -----------------------------

#define VA_NUM_ARGS_IMPL(_1,_2,_3,_4,_5,N,...) N
#define VA_NUM_ARGS_IMPL_(tuple) VA_NUM_ARGS_IMPL tuple
#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL_(( __VA_ARGS__, 5,4,3,2,1))
#define CONCAT(x,y) x ## y
#define PROXY(a,b) a b
#define CONCAT_(tuple) PROXY(CONCAT, tuple)
#define DEFINE_OVERLOAD(NAME, ...) CONCAT_((NAME, VA_NUM_ARGS(__VA_ARGS__)))

#define REP_IMPL_3(i,s,n) for (int i=s;i<=n;++i)
#define REP_IMPL_2(i,n) for (int i=1;i<=n;++i)
/*
* (i,n)  -> [1,n]
* (i,s,n)-> [s,n]
*/
#define REP(...) DEFINE_OVERLOAD(REP_IMPL_, __VA_ARGS__) (__VA_ARGS__)

#define RER_IMPL_3(i,n,s) for (int i=n;i>=s;--i)
#define RER_IMPL_2(i,n) for (int i=n;i>=1;--i)
/*
* (i,n)  -> [n,0]
* (i,s,n)-> [s,n]
*/
#define RER(...) DEFINE_OVERLOAD(RER_IMPL_, __VA_ARGS__) (__VA_ARGS__)

// --------------------- read functions ---------------------

void read(int& x1) { scanf("%d", &x1); }
void read(int& x1, int& x2) { scanf("%d %d", &x1, &x2); }
void read(int& x1, int& x2, int& x3) { scanf("%d %d %d", &x1, &x2, &x3); }
void read(int& x1, int& x2, int& x3, int& x4) { scanf("%d %d %d %d", &x1, &x2, &x3, &x4); }
void read(int& x1, int& x2, int& x3, int& x4, int& x5) { scanf("%d %d %d %d %d", &x1, &x2, &x3, &x4, &x5); }

void read(long& x1) { scanf("%ld", &x1); }
void read(long& x1, long& x2) { scanf("%ld %ld", &x1, &x2); }
void read(long& x1, long& x2, long& x3) { scanf("%ld %ld %ld", &x1, &x2, &x3); }
void read(long& x1, long& x2, long& x3, long& x4) { scanf("%ld %ld %ld %ld", &x1, &x2, &x3, &x4); }
void read(long& x1, long& x2, long& x3, long& x4, long& x5) { scanf("%ld %ld %ld %ld %ld", &x1, &x2, &x3, &x4, &x5); }

void read(long long& x1) { scanf("%lld", &x1); }
void read(long long& x1, long long& x2) { scanf("%lld %lld", &x1, &x2); }
void read(long long& x1, long long& x2, long long& x3) { scanf("%lld %lld %lld", &x1, &x2, &x3); }
void read(long long& x1, long long& x2, long long& x3, long long& x4) { scanf("%lld %lld %lld %lld", &x1, &x2, &x3, &x4); }
void read(long long& x1, long long& x2, long long& x3, long long& x4, long long& x5) { scanf("%lld %lld %lld %lld %lld", &x1, &x2, &x3, &x4, &x5); }

void read(unsigned int& x1) { scanf("%u", &x1); }
void read(unsigned int& x1, unsigned int& x2) { scanf("%u %u", &x1, &x2); }
void read(unsigned int& x1, unsigned int& x2, unsigned int& x3) { scanf("%u %u %u", &x1, &x2, &x3); }
void read(unsigned int& x1, unsigned int& x2, unsigned int& x3, unsigned int& x4) { scanf("%u %u %u %u", &x1, &x2, &x3, &x4); }
void read(unsigned int& x1, unsigned int& x2, unsigned int& x3, unsigned int& x4, unsigned int& x5) { scanf("%u %u %u %u %u", &x1, &x2, &x3, &x4, &x5); }

void read(unsigned long& x1) { scanf("%lu", &x1); }
void read(unsigned long& x1, unsigned long& x2) { scanf("%lu %lu", &x1, &x2); }
void read(unsigned long& x1, unsigned long& x2, unsigned long& x3) { scanf("%lu %lu %lu", &x1, &x2, &x3); }
void read(unsigned long& x1, unsigned long& x2, unsigned long& x3, unsigned long& x4) { scanf("%lu %lu %lu %lu", &x1, &x2, &x3, &x4); }
void read(unsigned long& x1, unsigned long& x2, unsigned long& x3, unsigned long& x4, unsigned long& x5) { scanf("%lu %lu %lu %lu %lu", &x1, &x2, &x3, &x4, &x5); }

void read(unsigned long long& x1) { scanf("%llu", &x1); }
void read(unsigned long long& x1, unsigned long long& x2) { scanf("%llu %llu", &x1, &x2); }
void read(unsigned long long& x1, unsigned long long& x2, unsigned long long& x3) { scanf("%llu %llu %llu", &x1, &x2, &x3); }
void read(unsigned long long& x1, unsigned long long& x2, unsigned long long& x3, unsigned long long& x4) { scanf("%llu %llu %llu %llu", &x1, &x2, &x3, &x4); }
void read(unsigned long long& x1, unsigned long long& x2, unsigned long long& x3, unsigned long long& x4, unsigned long long& x5) { scanf("%llu %llu %llu %llu %llu", &x1, &x2, &x3, &x4, &x5); }

template<typename T>
void read(int n, vector<T>& a) {
	REP(i, n) read(a[i]);
}

// --------------------- write functions ---------------------


void write(int& x1) { printf("%d", x1); }
void write(int& x1, int& x2) { printf("%d %d", x1, x2); }
void write(int& x1, int& x2, int& x3) { printf("%d %d %d", x1, x2, x3); }
void write(int& x1, int& x2, int& x3, int& x4) { printf("%d %d %d %d", x1, x2, x3, x4); }
void write(int& x1, int& x2, int& x3, int& x4, int& x5) { printf("%d %d %d %d %d", x1, x2, x3, x4, x5); }

void write(long& x1) { printf("%ld", x1); }
void write(long& x1, long& x2) { printf("%ld %ld", x1, x2); }
void write(long& x1, long& x2, long& x3) { printf("%ld %ld %ld", x1, x2, x3); }
void write(long& x1, long& x2, long& x3, long& x4) { printf("%ld %ld %ld %ld", x1, x2, x3, x4); }
void write(long& x1, long& x2, long& x3, long& x4, long& x5) { printf("%ld %ld %ld %ld %ld", x1, x2, x3, x4, x5); }

void write(long long& x1) { printf("%lld", x1); }
void write(long long& x1, long long& x2) { printf("%lld %lld", x1, x2); }
void write(long long& x1, long long& x2, long long& x3) { printf("%lld %lld %lld", x1, x2, x3); }
void write(long long& x1, long long& x2, long long& x3, long long& x4) { printf("%lld %lld %lld %lld", x1, x2, x3, x4); }
void write(long long& x1, long long& x2, long long& x3, long long& x4, long long& x5) { printf("%lld %lld %lld %lld %lld", x1, x2, x3, x4, x5); }

void write(unsigned int& x1) { printf("%u", x1); }
void write(unsigned int& x1, unsigned int& x2) { printf("%u %u", x1, x2); }
void write(unsigned int& x1, unsigned int& x2, unsigned int& x3) { printf("%u %u %u", x1, x2, x3); }
void write(unsigned int& x1, unsigned int& x2, unsigned int& x3, unsigned int& x4) { printf("%u %u %u %u", x1, x2, x3, x4); }
void write(unsigned int& x1, unsigned int& x2, unsigned int& x3, unsigned int& x4, unsigned int& x5) { printf("%u %u %u %u %u", x1, x2, x3, x4, x5); }

void write(unsigned long& x1) { printf("%lu", x1); }
void write(unsigned long& x1, unsigned long& x2) { printf("%lu %lu", x1, x2); }
void write(unsigned long& x1, unsigned long& x2, unsigned long& x3) { printf("%lu %lu %lu", x1, x2, x3); }
void write(unsigned long& x1, unsigned long& x2, unsigned long& x3, unsigned long& x4) { printf("%lu %lu %lu %lu", x1, x2, x3, x4); }
void write(unsigned long& x1, unsigned long& x2, unsigned long& x3, unsigned long& x4, unsigned long& x5) { printf("%lu %lu %lu %lu %lu", x1, x2, x3, x4, x5); }

void write(unsigned long long& x1) { printf("%llu", x1); }
void write(unsigned long long& x1, unsigned long long& x2) { printf("%llu %llu", x1, x2); }
void write(unsigned long long& x1, unsigned long long& x2, unsigned long long& x3) { printf("%llu %llu %llu", x1, x2, x3); }
void write(unsigned long long& x1, unsigned long long& x2, unsigned long long& x3, unsigned long long& x4) { printf("%llu %llu %llu %llu", x1, x2, x3, x4); }
void write(unsigned long long& x1, unsigned long long& x2, unsigned long long& x3, unsigned long long& x4, unsigned long long& x5) { printf("%llu %llu %llu %llu %llu", x1, x2, x3, x4, x5); }

template<typename T>
void write(int n, vector<T>& a) {
	REP(i, n) {
		write(a[i]);
		printf(" ");
	}
	printf("\n");
}

// ----------------------------------------------------------

/*
* Greatest common diviser
*
* Additional knowledge:
* Bezout identity https://en.wikipedia.org/wiki/Bézout%27s_identity
*/
template<typename T>
T gcd(T a, T b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

/*
*  Knut-Morris-Prat helper function
*/
auto kmp = [](const string& P)->vector<int> {
	const int m = P.length();
	vector<int> p(m + 1, 0);
	p[0] = 0;
	int k = 0;
	for (int q = 1; q < m; q++) {
		while (k > 0 && P[k] != P[q])
			k = p[k - 1];
		if (P[k] == P[q])
			k = k + 1;
		p[q] = k;
	}
	return p;
};

/*
*  Knut-Morris-Prat search
*/
auto find_kmp = [](const string& T, const string& P, vector<int>& kmp) {
	const int n = T.length();
	const int m = P.length();
	int q = 0;
	for (int i = 0; i < n; i++) {
		while (q > 0 && P[q] != T[i])
			q = kmp[q - 1];
		if (P[q] == T[i])
			q++;
		if (q == m)
			return i - m + 1;
	}
	return -1;
};