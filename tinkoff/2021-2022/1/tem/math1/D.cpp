#pragma GCC target("avx,avx2,sse3,ssse3,sse4.1,sse4.2")
#pragma GCC optimize(3)
#pragma GCC optimize("O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <bitset>
using namespace std;

typedef long long ll;

#ifdef DEBUG
	const int MAXN = 1e6;
#else
	const int MAXN = 1e6;
#endif

string s;
int N, n;
int prev_white[MAXN];
int next_black[MAXN];

inline void init() {
	memset(prev_white, -1, sizeof(prev_white));
	for (int i = 0; i < MAXN; i++) {
		next_black[i] = 1e9;
	}
}

int get(string& S, int& block_size) {
	n = S.size() / block_size * (block_size + 1);
	int min_right = 1e9;
	int max_left = -1;
	for (int i = 0; i < n; i+= block_size) {
		int l = i;
		int r = i + block_size - 1;
		int left_black = next_black[l];
		left_black = min(left_black, r + 1);
		int right_white = prev_white[r];
		right_white = max(right_white, l);
		if (left_black < right_white) {
			return -1;
		}
		min_right = min(min_right, left_black - i + 1);
		max_left = max(max_left, right_white - i + 1);
	}
	if (min_right <= max_left) {
		return -1;
	}
	return block_size - max_left;
}

inline void solve() {
	init();
	N = s.size();
	int ans = -1;
	int block_size = 0;
	for (int i = 0; i < MAXN; i++) {
		if (i >= N) {
			prev_white[i] = prev_white[i - 1];
			continue;
		}
		if (s[i] == '0') {
			prev_white[i] = i;
		}
		else if (i != 0) {
			prev_white[i] = prev_white[i - 1];
		}
	}
	for (int i = N - 1; i >= 0; i--) {
		if (s[i] == '1') {
			next_black[i] = i;
		}
		else if (i != N - 1) {
			next_black[i] = next_black[i + 1];
		}
	}
	for (int i = 1; i <= N; i++) {
		int res = get(s, i);
		if (res == -1) {
			continue;
		}
		int cur = N / i * res;
		cur += max(0, N % i - i + res); 
		if (ans < cur) {
			ans = cur;
			block_size = i;
		}
	}
	if (ans == -1) {
		cout << "-1\n";
		return;
	}
	int cntwhite = block_size - get(s, block_size);
	for (int i = 0; i < N; i++) {
		if (i % block_size < cntwhite) {
			cout << '0';
		}
		else {
			cout << '1';
		}
	}
	cout << '\n';
}

signed main() {
	#ifdef DEBUG
		freopen("F.in", "r", stdin);
		freopen("F.out", "w", stdout);
	#else
	
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (cin >> s)
		solve();
	return 0;
}
