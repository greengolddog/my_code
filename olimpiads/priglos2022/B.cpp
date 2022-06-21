#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	ll a, b, c;
	cin >> a >> b >> c;
	ll x1 = b - a, x2 = c - b;
	if (x1 == x2) {
		cout << a - x1 << '\n' << 1 << '\n';
		return;
	}
	if (x1 == x2 * 2) {
		cout << a + x2 << '\n' << 2 << '\n';
		return;
	}
	if (x1 * 2 == x2) {
		cout << b + x1 << '\n' << 3 << '\n';
	}
}

int main() {
	ll t = 1;
	//cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}
