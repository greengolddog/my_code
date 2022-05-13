#include <bits/stdc++.h>
typedef long long ll;

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

ll gcd(ll a, ll b) {
	return (min(a, b) == 0 ? max(a, b) : gcd(max(a, b) % min(a, b), min(a, b)));
}

pair<ll, ll> egcd_help(ll a, ll b) {
	if (b == 0) {
		return {1, 0};
	}
	auto[x, y] = egcd_help(b, a % b);
	return {y, x - a / b * y};
}

pair<ll, ll> egcd(ll a, ll b) {
	if (a < b) {
		auto[x, y] = egcd_help(b, a);
		return {y, x};
	} else {
		return egcd_help(a, b);
	}
}

ll binpow(ll x, ll p, ll m) {
	if (p == 0) {
		return 1;
	}
	if (p % 2 == 0) {
		ll s = binpow(x, p / 2, m);
		return s * s % m;
	} else {
		return binpow(x, p - 1, m) * x % m;
	}
}

int main() {
	freopen("rsa.in", "r", stdin);
	freopen("rsa.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, e, c;
	cin >> n >> e >> c;
	ll p, q;
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			p = i;
			q = n / i;
		}
	}
	ll mod = (p - 1) * (q - 1);
	ll d = egcd(e, mod).first;
	while (d < 0) {
		d += mod;
	}
	while (d >= 0) {
		d -= mod;
	}
	d += mod;
	cout << binpow(c, d, n);
}
