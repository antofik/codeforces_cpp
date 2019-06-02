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

typedef long L;
typedef unsigned long UL;
typedef unsigned long long ULL;
typedef unsigned long long ULL;

#define VA_NUM_ARGS_IMPL(_1,_2,_3,_4,_5,N,...) N
#define VA_NUM_ARGS_IMPL_(tuple) VA_NUM_ARGS_IMPL tuple
#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL_(( __VA_ARGS__, 5,4,3,2,1))
#define CONCAT(x,y) x ## y
#define PROXY(a,b) a b
#define CONCAT_(tuple) PROXY(CONCAT, tuple)
#define DEFINE_OVERLOAD(NAME, ...) CONCAT_((NAME, VA_NUM_ARGS(__VA_ARGS__)))

#define REP3(i,s,n) for (int i=s;i<n;++i)
#define REP2(i,n) for (int i=0;i<n;++i)
#define REP(...) DEFINE_OVERLOAD(REP, __VA_ARGS__) (__VA_ARGS__)

#define REPR3(i,s,n) for (int i=s;i>=n;--i)
#define REPR2(i,n) for (int i=n;i>=0;--i)
#define REPR(...) DEFINE_OVERLOAD(REPR, __VA_ARGS__) (__VA_ARGS__)

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