#include <bits/stdc++.h>

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

void solve() {
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll c1 = 0;
	for (auto i : s) {
		c1 += i == '1';
	}
	cout << (c1 % 2 == 1 ? "NO" : "YES") << '\n';
	if (c1 % 2 == 1) {
		return;
	}
	if (n == c1) {
		for (ll i = 1; i < n; i++) {
			cout << 0 << ' ' << i << '\n';
		}
		return;
	}
	deque<ll> a0;
	for (ll i = 0; i < n; i++) {
		if (s[i] == '0') {
			a0.push_back(i);
		}
	}
	if (a0.size() == 1) {
		for (ll i = 0; i < n; i++) {
			if (i != a0[0]) {
				cout << i << ' ' << a0[0] << '\n';
			}
		}
		return;
	}
	if (a0[0] != 0 || a0.back() != n - 1) {
		a0.push_front(a0.back());
		a0.pop_back();
	} else {
		while (a0[1] - a0[0] == 1) {
			a0.push_back(a0.front());
			a0.pop_front();
		}
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}
