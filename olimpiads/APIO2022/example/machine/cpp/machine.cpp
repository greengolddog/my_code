#include <bits/stdc++.h>
#include "machine.h"

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007;
const db PI = acos(-1);

mt19937 rnd32(time(0));
mt19937_64 rnd64(time(0));

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

template<typename T>
T square(T a) {
	return a * a;
}

template<>
struct std::hash<pair<ll, ll>> {
	ll operator() (pair<ll, ll> p) {
		return ((__int128)p.first * MOD + p.second) % INF64;
	}
};

vector<int> guess_permutation(int n) {
	vector<int> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		arr[i] = i;
	}
	if (n % 2 == 0) {
		arr[n - 1] = n;
		while (arr[n - 1] < n) {
			arr[n - 1] *= 2;
		}
		//arr[n - 2] += 1;
	}
	vector<int> ans = use_machine(arr);
	for (ll i = 0; i < 10; i++) {
		for (ll k = 0; k <= i; k++) {
			ll co = 0;
			for (auto j : arr) {
				co += ((j >> i) & 1) * ((j >> k) & 1);
			}
			ll con = 0;
			for (auto j : ans) {
				con += ((j >> i) & 1) * ((j >> k) & 1);
			}
			if (con != co) {
				for (auto& j : ans) {
					j ^= (1 << i);
				}
			}
		}
	}
	if (n % 2 == 0) {
		for (auto& i : ans) {
			if (i >= n) {
				i = n - 1;
				continue;
			}
			if (i == n - 1) {
				//i -= 1;
			}
		}
	}
	return ans;
}
