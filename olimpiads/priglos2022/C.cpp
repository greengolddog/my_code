#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	return (min(a, b) == 0 ? max(a, b) : gcd(max(a, b) % min(a, b), min(a, b)));
}

void solve() {
	ll n, a, b;
	cin >> n >> a >> b;
	cout << n / a + n / b - n / (a * b / gcd(a, b));
}

int main() {
	ll t = 1;
	//cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}
