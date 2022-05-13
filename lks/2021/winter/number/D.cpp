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
	ll a, b, n, m;
	cin >> a >> b >> n >> m;
	ll ans = a * m * egcd(m, n).first + b * n * egcd(n, m).first;
	while (ans < 0) {
		ans += n * m;
	}
	while (ans >= 0) {
		ans -= n * m;
	}
	ans += n * m;
	cout << ans;
}
