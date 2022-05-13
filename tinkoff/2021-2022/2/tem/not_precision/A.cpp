#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("vpt")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
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
#include <bits/stdc++.h>
typedef int_fast64_t ll;

const ll INF = 9'000'000'000'000'000'000;

template<typename T>
bool assign_max(T& a, T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_min(T& a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

using namespace std;

mt19937_64 rnd(time(0));

ll count(vector<ll> arr) {
	unordered_map<ll, ll> up, down;
	ll c = 0;
	for (ll i = 0; i < arr.size(); i++) {
		c += up[arr[i] - i];
		up[arr[i] - i]++;
		c += down[arr[i] + i];
		down[arr[i] + i]++;
	}
	return c;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		arr[i] = i;
	}
	if (n < 10) {
		do {
			if (count(arr) == 0) {
				break;
			}
		} while (next_permutation(arr.begin(), arr.end()));
	} else {
		shuffle(arr.begin(), arr.end(), rnd);
	}
	while (true) {
		ll N = 2'000, c = count(arr);
		for (ll i = 0; i < N; i++) {
			if (c == 0) {
				break;
			}
			ll a = rnd() % n, b = rnd() % n;
			swap(arr[a], arr[b]);
			ll nc = count(arr);
			if (nc < c) {
				c = nc;
			} else {
				double x = (rnd() % 1'000'000'000'000'000) / 1'000'000'000'000'000;
				if (x > exp(-(double)i / N) && false) {
					c = nc;
				} else {
					swap(arr[a], arr[b]);
				}
			}
		}
		if (c == 0) {
			for (auto i : arr) {
				cout << i + 1 << ' ';
			}
			break;
		}
	}
}
