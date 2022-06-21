#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	ll n;
	cin >> n;
	map<ll, ll> m;
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		m[x]++;
	}
	for (auto[a, b] : m) {
		if (b == 1) {
			cout << a;
			return;
		}
	}
	cout << -1;
}

int main() {
	ll t = 1;
	//cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}
