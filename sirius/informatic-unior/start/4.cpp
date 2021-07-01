#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	map<ll, vector<ll>> arr;
	set<ll> all;
	for (ll i = 0; i < n; i++) {
		ll s, f;
		cin >> s >> f;
		if (all.find(s) != all.end()) {
			arr[s].push_back(f);
		} else {
			all.insert(s);
			arr[s] = vector<ll>(1, f);
		}
	}
	for (auto i : all) {
		sort(arr[s].begin(), arr[s].end());
	}
	ll zap;
	cin >> zap;
	for (ll i = 0; i < zap; i++) {
		ll s, f;
		cin >> s >> f;
		if (all.find(s) == all.end()) {
			cout << abs(f-s) << '\n';
			continue;
		}
		ll l = 0, r = n;
		while (l - r > 1) {
			ll mid = (l+r)/2;
			if (arr[mid] > f) {
				r = mid;
			else {
				l = mid;
			}
		}
		if (l == n-1) {
			cout << abs(arr[l] - f) << '\n';
		} else {
			cout << min(abs(arr[l] - f), ans(arr[l+1] - f)) << '\n';
		}
	}
}
