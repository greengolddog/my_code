#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<tuple<ll, ll, ll>> arr;
	vector<ll> mass;
	for (ll i = 0; i < n; i++) {
		ll l, r;
		cin >> l >> r;
		mass.push_back(l);
		arr.push_back({l, 0, i});
		arr.push_back({r-1, 1, i});
	}
	sort(arr.begin(), arr.end());
	set<pair<ll, ll>> s;
	ll ans = 1000000000000;
	pair<ll, ll> a = {0, 0};
	for (auto&[l, o, i] : arr) {
		if (o == 0) {
			s.insert({l, i});
		} else {
			s.erase({mass[i], i});
			if (s.size() != 0) {
				if (ans > l-max(s.rbegin()->first, mass[i])) {
					ans = l-max(s.rbegin()->first, mass[i]);
					a = {s.rbegin()->second, i};
				}
			}
		}
	}
	if (ans == 1000000000000) {
		cout << 0;
		return 0;
	}
	cout << a.first+1 << ' ' << a.second+1;
}
