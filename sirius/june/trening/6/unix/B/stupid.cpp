#pragma GCC optimize("Ofast")
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
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		ll _;
		cin >> _;
	}
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	ll ans = 0;
	while (h > 0) {
		ans++;
		h -= arr.back();
		arr.pop_back();
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
