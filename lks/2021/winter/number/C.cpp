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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll a, m;
	cin >> a >> m;
	if (gcd(a, m) != 1) {
		cout << -1;
		return 0;
	}
	auto[x, y] = egcd(a, m);
	while (x < 0) {
		x += m;
	}
	cout << x % m;
}
