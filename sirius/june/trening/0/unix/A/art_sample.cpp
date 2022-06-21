#include <bits/stdc++.h>
#include "art.h"

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007;
ll N;
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

map<pair<ll, ll>, bool> m;

bool cmp(int a, int b) {
	if (m.find(make_pair(a, b)) != m.end()) {
		return m[make_pair(a, b)];
	}
	vector<int> q;
	q.push_back(a);
	q.push_back(b);
	for (ll i = 1; i <= N; i++) {
		if (i != a && i != b) {
			q.push_back(i);
		}
	}
	ll x1 = publish(q);
	swap(q[0], q[1]);
	ll x2 = publish(q);
	m[make_pair(a, b)] = x1 < x2;
	m[make_pair(b, a)] = x2 < x1;
	return x1 < x2;
}

vector<int> to_v(deque<int> d) {
	vector<int> ans;
	for (auto i : d) {
		ans.push_back(i);
	}
	return ans;
}

void solve(int n) {
	N = n;
	deque<int> arr(n);
	for (ll i = 0; i < n; i++) {
		arr[i] = i + 1;
	}
	vector<int> ans(n, 0);
	vector<ll> anss(n, 0);
	for (ll i = 0; i < n; i++) {
		anss[i] = publish(to_v(arr));
		arr.push_back(arr.front());
		arr.pop_front();
	}
	for (ll i = 0; i < n; i++) {
		ans[n - (-(anss[i] - anss[(i + 1) % n] - n + 1)) / 2 - 1] = i + 1;
	}
	//shuffle(arr.begin(), arr.end(), rnd32);
	//for (ll i = n - 1; i >= 0; i--) {
	//	for (ll j = 0; j < i; j++) {
	//		if (cmp(arr[j], arr[j + 1])) {
	//			swap(arr[j], arr[j + 1]);
	//		}
	//	}
	//}
	//stable_sort(arr.begin(), arr.end(), cmp);
	answer(ans);
}
