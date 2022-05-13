#include <bits/stdc++.h>
typedef long long ll;

const ll INF = 9'000'000'000'000'000'000;

using namespace std;

mt19937_64 rnd(time(0));

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

__int128 binpow(__int128 a, __int128 t, __int128 p) {
	if (t == 0) {
		return 1;
	}
	if (t % 2 == 0) {
		__int128 x = binpow(a, t / 2, p);
		return x * x % p;
	} else {
		return binpow(a, t - 1, p) * a % p;
	}
}

bool is_prime(ll p) {
	if (p < 2) {
		return false;
	}
	if (p < 4) {
		return true;
	}
	ll t = p - 1, s = 0;
	while (t % 2 == 0) {
		t /= 2;
		s++;
	}
	ll a = (rnd() % (p - 3)) + 2;
	ll g = binpow(a, t, p);
	for (ll i = 0; i <= s; i++) {
		if (g == 1) {
			return true;
		}
		if (g != p - 1 && (__int128)g * g % p == 1) {
			return false;
		}
		g = (__int128)g * g % p;
	}
	return g == 1;
}

bool check_smart(ll x) {
	if (x == 1) {
		return false;
	}
	for (ll i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

bool check_stupid(ll x) {
	bool b = true;
	for (ll i = 0; i < 20; i++) {
		b = b && is_prime(x);
	}
	return b;
}

void solve() {
	ll x;
	cin >> x;
	cout << (check_stupid(x) ? "YES" : "NO") << '\n';
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	bool b = true;
	if (b) {
		freopen("again.in", "r", stdin);
		freopen("again.out", "w", stdout);
		ll t;
		cin >> t;
		for (ll i = 0; i < t; i++) {
			solve();
		}
	} else {
		while (true) {
			ll x = rnd() % 1'000'000'000'000'000'000 + 1;
			if (check_smart(x) != check_stupid(x)) {
				cout << x;
				break;
			}
		}
	}
}
