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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll l, r;
	cin >> l >> r;
	ll n = r;
	vector<ll> p, d(n + 1, -1);
	for (ll i = 2; i <= n; i++) {
		if (d[i] == -1) {
			d[i] = p.size();
			p.push_back(i);
		}
		for (ll j = 0; j <= d[i] && p[j] * i <= n; j++) {
			d[p[j] * i] = j;
		}
	}
	ll ans = 0;
	for (ll i = l; i <= r; i++) {
		ans += p[d[i]];
	}
	cout << ans;
}
