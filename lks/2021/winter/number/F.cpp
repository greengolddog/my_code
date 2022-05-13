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

ll gcd(ll a, ll b) {
	return (min(a, b) == 0 ? max(a, b) : gcd(max(a, b) % min(a, b), min(a, b)));
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

bool check_stupid(ll x) {
	bool b = true;
	for (ll i = 0; i < 20; i++) {
		b = b && is_prime(x);
	}
	return b;
}

ll next_rand(ll x, ll n) {
	return ((__int128)x * x + 1) % n;
}

pair<ll, ll> pollard(ll n) {
	ll z = 0;
	while (true) {
		ll k = ceil(sqrt(ceil(sqrt(n))));
		ll x = (rnd() % (n - 3)) + 2;
		for (ll i = 0; i < k; i++) {
			x = next_rand(x, n);
		}
		ll y = next_rand(x, n);
		for (ll i = 0; i < k; i++) {
			ll g = gcd(max(x, y) - min(x, y), n);
			if (g != 1 && g != n) {
				return {g, n / g};
			}
			y = next_rand(y, n);
		}
		z++;
	}
}

void solve() {
	ll x;
	cin >> x;
	vector<ll> arr(1, x);
	vector<ll> p;
	while (!arr.empty()) {
		vector<ll> na;
		for (auto i : arr) {
			for (ll j = 2; j < 100; j++) {
				while (i % j == 0) {
					p.push_back(j);
					i = i / j;
				}
			}
			if (check_stupid(i)) {
				p.push_back(i);
			} else {
				if (i > 100'000'000'000'000) {
					auto[a, b] = pollard(i);
					na.push_back(a);
					na.push_back(b);
				} else {
					for (ll j = 100; j * j <= i; j++) {
						while (i % j == 0) {
							p.push_back(j);
							i /= j;
						}
					}
					if (i > 1) {
						p.push_back(i);
					}
				}
			}
		}
		arr = na;
	}
	sort(p.begin(), p.end());
	for (auto i : p) {
		cout << i << ' ';
	}
}

int main() {
	freopen("pollard.in", "r", stdin);
	freopen("pollard.out", "w", stdout);
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	solve();
}
