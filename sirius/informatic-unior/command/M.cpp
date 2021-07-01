#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	ll n;
	cin >> n;
	vector<pair<ll, pair<ll, ll>>> arr(n, {0, {0, 0}});
	set<pair<ll, ll>> s;
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second.first;
		arr[i].second.second = i;
		arr[i].second.first = -arr[i].second.first;
		s.insert({-arr[i].second.first, i});
	}
	sort(arr.begin(), arr.end());
	for (auto[_, ri] : arr) {
		auto[r, i] = ri;
		s.erase({-r, i});
		if ((s.size() > 0) && (s.begin()->first <= -r)) {
			cout << s.begin()->second+1 << ' ' << i+1;
			return 0;
		}
	}
	cout << -1 << ' ' << -1;
}
