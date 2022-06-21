#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll INF32 = 2'000'000'000, INF64 = 9'000'000'000'000'000'000, LOG = 25;

template<typename T>
bool assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_max(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

void solve() {
	ll n, h;
	cin >> n >> h;
	vector<ll> all;
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		while (x > 0) {
			all.push_back(x);
			x /= 2;
		}
	}
	for (ll j = 0; j < n; j++) {
		ll x;
		cin >> x;
		all.push_back(x);
	}
	ll ans = 0;
	sort(all.begin(), all.end());
	while (h > 0) {
		ans++;
		h -= all.back();
		all.pop_back();
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
