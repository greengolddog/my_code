#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF = 9'000'000'000'000'000'000;
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

ll binpow(ll a, ll b, ll mod) {
	if (b == 0) {
		return 1;
	}
	if (b % 2 == 0) {
		ll x = binpow(a, b / 2, mod);
		return (__int128)x * x % mod;
	} else {
		return (__int128)binpow(a, b - 1, mod) * a % mod;
	}
}

bool test(ll n) {
	ll a = rnd64() % (n - 1) + 1;
	ll now = n - 1, col = 0;
	while (now % 2 == 0) {
		now /= 2;
		col++;
	}
	a = binpow(a, now, n);
	if (a == 1) {
		return true;
	}
	for (ll i = 0; i <= col; i++) {
		if (a == n - 1) {
			return true;
		}
		a = (__int128)a * a % n;
	}
	return false;
}

bool check(ll x) {
	bool b = true;
	for (ll i = 0; i < 20; i++) {
		b = b && test(x);
	}
	return b;
}

void solve() {
	ll x;
	cin >> x;
	if (x == 1) {
		cout << "NO" << '\n';
		return;
	}
	cout << (check(x) ? "YES" : "NO") << '\n';
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
