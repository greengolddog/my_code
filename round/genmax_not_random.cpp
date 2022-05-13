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

mt19937_64 rnd(time(0));

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n = 200'000, max_x = 1'000'000'000;
	cout << n << '\n';
	ll y = 0;
	for (ll i = 1; i < n; i++) {
		ll xx = 0;
		cout << (xx == 0 ? '+' : '?') << ' ';
		ll l = 0, r = y;
		cout << l << ' ' << r << ' ';
		ll x = max_x;
		cout << x << '\n';
		if (xx == 0) {
			y += x;
		}
	}
	cout << '?' << ' ' << 0 << ' ' << y;
}
