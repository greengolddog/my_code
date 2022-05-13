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

void solve() {
	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	ll a = INF;
	sort(arr.begin(), arr.end());
	vector<ll> ans;
	do {
		ll now = 0;
		for (ll l = 0; l < n; l++) {
			ll mx = INF;
			for (ll r = l; r < n; r++) {
				assign_min(mx, arr[r]);
				now += mx;
			}
		}
		if (assign_min(a, now)) {
			ans = arr;
		}
	} while (next_permutation(arr.begin(), arr.end()));
	cout << a << '\n';
	for (auto i : ans) {
		cout << i << ' ';
	}
	cout << '\n';
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		solve();
	}
}
